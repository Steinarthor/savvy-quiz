[@react.component]
let make = (~questionStream: Stream.t(Types.question)) => {
  let (currentQuestion, setCurrentQuestion) = React.useState(() => None);

  let nextQuestion = () => {
    switch (Stream.next(questionStream)) {
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
    [|questionStream|],
  );

  <div> <Question currentQuestion nextQuestion /> </div>;
};