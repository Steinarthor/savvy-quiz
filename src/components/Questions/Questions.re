[@react.component]
let make = (~questionStream: Stream.t(Savvy.APIDecode.CategoryType.t)) => {
  let (currentQuestion, setCurrentQuestion) = React.useState(() => None);

  let nextQuestion = () => {
    switch (Stream.next(questionStream)) {
    | question => setCurrentQuestion(_ => Some(question))
    | exception Stream.Failure => print_endline("No questions left")
    };
  };

  React.useEffect0(() => {
    // We do this to show the first question in the stream on mount.
    nextQuestion();
    None;
  });

  <div> <Question currentQuestion nextQuestion /> </div>;
};