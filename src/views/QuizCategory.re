type state = {questions: array(Types.question)};

[@react.component]
let make = (~title: string, ~categoryId: string) => {
  let (numberOfQuestions, setNumberOfQuestions) = React.useState(() => 1);
  let (questions, setQuestions) = React.useState(() => [||]);
  let (difficulty, setDifficulty) = React.useState(() => "any");
  let (quizType, setQuizType) = React.useState(() => "any");
  let (showQuestions, setShowQuestions) = React.useState(() => false);
  let quizContext = QuizContext.useQuiz();
  let selectDiffultLevel = (level: string) => setDifficulty(_ => level);
  let setQuestionType = (quizType: string) => setQuizType(_ => quizType);

  let difficultyLevel: list(Types.option) = [
    {value: "any", label: "Any"},
    {value: "easy", label: "Easy"},
    {value: "medium", label: "Medium"},
    {value: "hard", label: "Hard"},
  ];
  let questionType: list(Types.option) = [
    {value: "any", label: "Any"},
    {value: "multiple", label: "Multiple"},
    {value: "boolean", label: "Boolean"},
  ];

  let constructUrl =
    String.(
      (baseUrl: string) => {
        switch (difficulty, quizType) {
        | (x, y) when x !== "any" && y === "any" =>
          concat("&", [baseUrl, "difficulty=" ++ difficulty])
        | (x, y) when x !== "any" && y !== "any" =>
          concat(
            "&",
            [baseUrl, "difficulty=" ++ difficulty, "type=" ++ quizType],
          )
        | (x, y) when x === "any" && y !== "any" =>
          concat("&", [baseUrl, "type=" ++ quizType])
        | _ => baseUrl
        };
      }
    );

  let createQuiz = {
    let baseUrl =
      "https://opentdb.com/api.php?amount="
      ++ string_of_int(numberOfQuestions)
      ++ "&category="
      ++ categoryId
      ++ "&token="
      ++ quizContext.token;
    Js.Promise.(
      () => {
        Fetch.fetch(constructUrl(baseUrl))
        |> then_(Fetch.Response.json)
        |> then_(json => {
             let categoryTypeResponse =
               APIDecode.CategoryTypeResult.decode(json);
             setQuestions(_ => categoryTypeResponse.results);
             setShowQuestions(_ => true);
             resolve();
           })
        |> ignore;
      }
    );
  };
  let questionStream = MakeStream.array(~arrayList=questions);
  <div>
    <h1> {React.string(title)} </h1>
    <Input
      value={string_of_int(numberOfQuestions)}
      onChange={event =>
        setNumberOfQuestions(ReactEvent.Form.target(event)##value)
      }
      type_="number"
      isValid=true
      placeholder="Number of questions"
      required=true
      max="50"
    />
    <Select options=difficultyLevel onChange=selectDiffultLevel />
    <Select options=questionType onChange=setQuestionType />
    <Button
      text="Create Quiz"
      type_="button"
      onClick={_ => createQuiz()}
      disabled=false
    />
    {showQuestions ? <Questions questionStream /> : React.null}
  </div>;
};