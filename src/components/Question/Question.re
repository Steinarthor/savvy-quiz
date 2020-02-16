[@react.component]
let make =
    (
      ~currentQuestion: option(Types.question),
      ~setSelectedQuestion: string => unit,
      ~selectedQuestion: option(string),
      ~answer: string,
    ) => {
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
           (question: string) =>
             <p
               key=question
               className={Cn.make([
                 QuestionStyles.question,
                 QuestionStyles.selectedQuestion->Cn.ifTrue(
                   Belt.Option.getWithDefault(selectedQuestion, "")
                   === question,
                 ),
                 QuestionStyles.correctQuestion->Cn.ifTrue(
                   answer === question,
                 ),
               ])}
               dangerouslySetInnerHTML={"__html": question}
               onClick={_ => setSelectedQuestion(question)}
             />,
           answers,
         )
         |> Array.of_list
         |> React.array;
       },
     )}
  </div>;
};