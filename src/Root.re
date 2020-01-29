type action =
  | SetToken(string);

let intialState: Types.quizContext = {token: "", questions: []};

let reducer = (initialState: Types.quizContext, action) => {
  switch (action) {
  | SetToken(token) => {...initialState, token}
  };
};
// Right now I'm not passing down the dispatch function or anything like that
// https://dev.to/margaretkrutikova/reason-react-context-explained-in-action-5eki
// TODO: Add refresh token if response is 4.
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, intialState);
  // Fetching token on mount.
  React.useEffect0(() => {
    Js.Promise.(
      Fetch.fetch("https://opentdb.com/api_token.php?command=request")
      |> then_(res => Fetch.Response.json(res))
      |> then_(json => {
           let tokenResponse = APIDecode.RequestToken.decode(json);
           dispatch(SetToken(tokenResponse.token));
           resolve();
         })
    )
    |> ignore;
    None;
  });
  <QuizProvider value=state> <Router /> </QuizProvider>;
};