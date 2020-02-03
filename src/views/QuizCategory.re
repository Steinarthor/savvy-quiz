type state = {
  numberOfQuestions: int,
  questions: array(Types.question),
  difficulty: string,
  quizType: string,
  showQuestions: bool,
};

type action =
  | SetNumberOfQuestions(int)
  | SetQuestions(array(Types.question))
  | SetDifficulty(string)
  | SetQuizType(string)
  | ShowQuestions(bool)
  | FetchQuestions(string, string, array(Types.question) => unit);

let initialState: state = {
  numberOfQuestions: 1,
  questions: [||],
  difficulty: "any",
  quizType: "any",
  showQuestions: false,
};

let reducer = (state, action) => {
  switch (action) {
  | SetNumberOfQuestions(numberOfQuestions) => {
      ...state,
      questions: [||],
      numberOfQuestions,
    }
  | SetQuestions(questions) => {...state, questions}
  | SetDifficulty(difficulty) => {...state, difficulty}
  | SetQuizType(quizType) => {...state, quizType}
  | ShowQuestions(showQuestions) => {...state, showQuestions}
  | FetchQuestions(categoryId, token, update) =>
    Js.Promise.(
      Network.fetchQuestions(
        state.numberOfQuestions,
        categoryId,
        token,
        state.difficulty,
        state.quizType,
      )
      |> then_((res: Types.CategoryTypeResult.t) =>
           update(res.results) |> resolve
         )
    )
    |> ignore;
    state;
  };
};

[@react.component]
let make = (~title: string, ~categoryId: string) => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let updateQuestionState = questions => {
    dispatch(SetQuestions(questions));
    dispatch(ShowQuestions(true));
  };
  let quizContext = QuizContext.useQuiz();
  let selectDiffultLevel = (level: string) =>
    dispatch(SetDifficulty(level));
  let setQuestionType = (quizType: string) =>
    dispatch(SetQuizType(quizType));

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
  let questionStream = MakeStream.array(~arrayList=state.questions);

  <div>
    <h1> {React.string(title)} </h1>
    <Input
      value={string_of_int(state.numberOfQuestions)}
      onChange={event =>
        dispatch(SetNumberOfQuestions(ReactEvent.Form.target(event)##value))
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
      onClick={_ =>
        dispatch(
          FetchQuestions(categoryId, quizContext.token, updateQuestionState),
        )
      }
      disabled=false
    />
    {state.showQuestions ? <Questions questionStream /> : React.null}
  </div>;
};