let quizContext: Types.quizContext = {
  state: {
    token: "",
    questions: [||],
    quizStream: MakeStream.array(~arrayList=[||]),
    numberOfQuestions: 0,
    quizDifficulty: "any",
    quizType: "any",
  },
  dispatch: _ => (),
};
let context = React.createContext(quizContext);

let useQuiz = () => React.useContext(context);