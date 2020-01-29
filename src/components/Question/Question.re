[@react.component]
let make =
    (
      ~currentQuestion: option(APIDecode.CategoryType.t),
      ~nextQuestion: unit => unit,
    ) => {
  <div>
    {currentQuestion->Belt.Option.mapWithDefault(React.null, currentQuestion =>
       <h1 dangerouslySetInnerHTML={"__html": currentQuestion.question} />
     )}
    {currentQuestion->Belt.Option.mapWithDefault(
       React.null,
       currentQuestion => {
         let answers = [
           currentQuestion.correctAnswer,
           ...currentQuestion.incorretAnswers,
         ];
         List.map(
           (answer: string) =>
             <p
               key=answer
               dangerouslySetInnerHTML={"__html": answer}
               onClick={_ => nextQuestion()}
             />,
           answers,
         )
         |> Array.of_list
         |> React.array;
       },
     )}
  </div>;
};