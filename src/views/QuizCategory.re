[@react.component]
let make = (~title: string, ~categoryId: string) => {
  let (showQuestions, setShowQuestions) = React.useState(_ => false);
  let quizContext = QuizContext.useQuiz();
  let createQuiz = () => {
    Js.Promise.(
      Network.fetchQuestions(
        quizContext.state.numberOfQuestions,
        categoryId,
        quizContext.state.token,
        quizContext.state.quizDifficulty,
        quizContext.state.quizType,
      )
      |> then_((res: Types.CategoryTypeResult.t) => {
           quizContext.dispatch(SetQuestions(res.results));
           quizContext.dispatch(MakeStream);
           resolve();
         })
    )
    |> ignore;
  };

  let selectDiffultLevel = (level: string) =>
    quizContext.dispatch(SetQuizDifficulty(level));
  let setQuestionType = (quizType: string) =>
    quizContext.dispatch(SetQuizType(quizType));

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

  <>
    <h1> {React.string(title)} </h1>
    <div className=QuizCategoryStyles.quizCategory>
      <Input
        value={string_of_int(quizContext.state.numberOfQuestions)}
        onChange={event =>
          quizContext.dispatch(
            SetNumberOfQuestions(ReactEvent.Form.target(event)##value),
          )
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
        onClick={_ => {
          createQuiz();
          setShowQuestions(_ => true);
        }}
        disabled=false
      />
      {showQuestions ? <Questions /> : React.null}
    </div>
  </>;
};