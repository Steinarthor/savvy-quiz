[@react.component]
let make = () => {
  let (currentQuestion, setCurrentQuestion) = React.useState(() => None);
  let (questionCount, setQuestionCount) = React.useState(_ => 0);
  let quizContext = QuizContext.useQuiz();
  let nextQuestion = () => {
    switch (Stream.next(quizContext.state.quizStream)) {
    | question =>
      setCurrentQuestion(_ => Some(question));
      setQuestionCount(count => count + 1);
    | exception Stream.Failure => print_endline("No questions left")
    };
  };

  let totalQuestions = Array.length(quizContext.state.questions);

  React.useEffect1(
    () => {
      // We do this to show the first question in the stream on mount..
      nextQuestion();
      None;
    },
    [|quizContext.state.quizStream|],
  );
  quizContext.state.fetchingQuestions
    ? <div> {React.string("Loading...")} </div>
    : <>
        <QuestionCount count=questionCount total=totalQuestions />
        <Question currentQuestion nextQuestion />
      </>;
};