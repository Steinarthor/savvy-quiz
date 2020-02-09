[@react.component]
let make = () => {
  let quizContext = QuizContext.useQuiz();
  React.useEffect1(
    _ => {
      quizContext.dispatch(ClearContext);
      None;
    },
    [||],
  );
  <div className=AppStyles.container>
    {quizContext.state.categories
     |> Array.map((category: Types.category) =>
          <Category category key={string_of_int(category.id)} />
        )
     |> React.array}
  </div>;
};