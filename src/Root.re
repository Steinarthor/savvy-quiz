let initialState: Types.quizState = {
  token: "",
  questions: [||],
  categories: [||],
  quizStream: MakeStream.array(~arrayList=[||]),
  numberOfQuestions: 0,
  quizDifficulty: "any",
  quizType: "any",
  fetchingQuestions: false,
};

let reducer = (state: Types.quizState, action: Types.quizAction) => {
  switch (action) {
  | SetNumberOfQuestions(numberOfQuestions) => {...state, numberOfQuestions}
  | SetQuizDifficulty(quizDifficulty) => {...state, quizDifficulty}
  | SetQuizType(quizType) => {...state, quizType}
  | SetCategories(categories) => {...state, categories}
  | SetQuestions(questions) => {...state, questions}
  | SetToken(token) => {...state, token}
  | FetchingQuestions(fetchingQuestions) => {...state, fetchingQuestions}
  | MakeStream => {
      ...state,
      quizStream: MakeStream.array(~arrayList=state.questions),
    }
  | ClearContext => {
      ...state,
      numberOfQuestions: initialState.numberOfQuestions,
      quizDifficulty: initialState.quizDifficulty,
      quizType: initialState.quizType,
      quizStream: MakeStream.array(~arrayList=[||]),
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

    // Fetching categories
    Js.Promise.(
      Fetch.fetch("https://opentdb.com/api_category.php")
      |> then_(Fetch.Response.json)
      |> then_(json => {
           let response = Types.Categories.decode(json);
           dispatch(SetCategories(response.trivia_categories));
           resolve();
         })
      |> catch(_err => Js.Promise.resolve())
      |> ignore
    );
    None;
  });
  <QuizProvider value=contextValue>
    <> <Header /> <Router /> </>
  </QuizProvider>;
};