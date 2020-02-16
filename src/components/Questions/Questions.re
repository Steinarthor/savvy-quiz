[@react.component]
let make = () => {
  let (currentQuestion, setCurrentQuestion) = React.useState(() => None);
  let (selectedQuestion, setSelectedQuestion) = React.useState(() => None);
  let (questionCount, setQuestionCount) = React.useState(_ => 0);
  let (answer, setCorrectAnswer) = React.useState(_ => "");

  let quizContext = QuizContext.useQuiz();
  let nextQuestion = () => {
    switch (Stream.next(quizContext.state.quizStream)) {
    | question =>
      setCurrentQuestion(_ => Some(question));
      setQuestionCount(count => count + 1);
    | exception Stream.Failure => print_endline("No questions left")
    };
  };

  let correctAnswer =
    Belt.Option.(
      (answer: option(Types.question)) => {
        answer->mapWithDefault((), (answer: Types.question) =>
          setCorrectAnswer(_ => answer.correctAnswer)
        );
      }
    );

  let setSelectedQuestion = question => {
    correctAnswer(currentQuestion);
    setSelectedQuestion(_ => Some(question));
  };

  let totalQuestions = Array.length(quizContext.state.questions);
  React.useEffect1(
    () => {
      nextQuestion();
      None;
    },
    [|quizContext.state.quizStream|],
  );
  quizContext.state.fetchingQuestions
    ? <div> {React.string("Loading...")} </div>
    : <div className=QuestionStyles.questions>
        <QuestionCount count=questionCount total=totalQuestions />
        <Process count=questionCount totalQuestions />
        <Question
          currentQuestion
          setSelectedQuestion
          selectedQuestion
          answer
        />
        <Button
          text="Next"
          type_="button"
          onClick={_ => nextQuestion()}
          disabled=false
        />
      </div>;
};