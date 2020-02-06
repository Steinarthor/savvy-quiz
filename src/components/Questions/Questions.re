[@react.component]
let make = () => {
  let (currentQuestion, setCurrentQuestion) = React.useState(() => None);
  let quizContext = QuizContext.useQuiz();
  let nextQuestion = () => {
    switch (Stream.next(quizContext.state.quizStream)) {
    | question => setCurrentQuestion(_ => Some(question))
    | exception Stream.Failure => print_endline("No questions left")
    };
  };

  React.useEffect1(
    () => {
      // We do this to show the first question in the stream on mount..
      nextQuestion();
      None;
    },
    [|quizContext.state.quizStream|],
  );

  <Question currentQuestion nextQuestion />;
};