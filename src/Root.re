let initialState: Types.quizState = {
  token: "",
  questions: [||],
  quizStream: MakeStream.array(~arrayList=[||]),
  numberOfQuestions: 0,
  quizDifficulty: "any",
  quizType: "any",
};

let reducer = (state: Types.quizState, action: Types.quizAction) => {
  switch (action) {
  | SetNumberOfQuestions(numberOfQuestions) => {...state, numberOfQuestions}
  | SetQuizDifficulty(quizDifficulty) => {...state, quizDifficulty}
  | SetQuizType(quizType) => {...state, quizType}
  | SetQuestions(questions) => {...state, questions}
  | SetToken(token) => {...state, token}
  | MakeStream => {
      ...state,
      quizStream: MakeStream.array(~arrayList=state.questions),
    }
  };
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let contextValue: Types.quizContext = {state, dispatch};
  // Fetching token on mount.
  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch("https://opentdb.com/api_token.php?command=request")
      |> then_(res => Fetch.Response.json(res))
      |> then_(json => {
           let tokenResponse = Types.RequestToken.decode(json);
           dispatch(SetToken(tokenResponse.token));
           resolve();
         })
    )
    |> ignore;
    None;
  });
  <QuizProvider value=contextValue> <Router /> </QuizProvider>;
};