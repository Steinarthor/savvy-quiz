[@react.component]
let make = (~currentQuestion: option(Types.question)) => {
  <div className=QuestionStyles.questions>
    {currentQuestion->Belt.Option.mapWithDefault(React.null, currentQuestion =>
       <h1
         className=QuestionStyles.questionText
         dangerouslySetInnerHTML={"__html": currentQuestion.question}
       />
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
             />,
           answers,
         )
         |> Array.of_list
         |> React.array;
       },
     )}
  </div>;
};