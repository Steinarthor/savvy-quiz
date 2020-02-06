[@react.component]
let make =
    (~currentQuestion: option(Types.question), ~nextQuestion: unit => unit) => {
  <div className=QuestionStyles.questions>
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
               className=QuestionStyles.question
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