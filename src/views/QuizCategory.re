[@react.component]
let make = (~title: string, ~categoryId: string) => {
  let (showQuestions, setShowQuestions) = React.useState(_ => false);
  let (showCreateQuiz, setShowCreateQuiz) = React.useState(_ => true);
  let toggleShowQuestions = () => setShowQuestions(_ => true);
  let toggleShowCreate = () => setShowCreateQuiz(_ => false);
  let quizContext = QuizContext.useQuiz();

  React.useEffect1(
    _ => {
      quizContext.dispatch(ClearContext);
      None;
    },
    [||],
  );

  <>
    <h1> {React.string(title)} </h1>
    {showCreateQuiz
       ? <Create categoryId toggleShowQuestions toggleShowCreate />
       : React.null}
    {showQuestions ? <Questions /> : React.null}
  </>;
};