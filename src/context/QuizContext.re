let quizContext: Types.quizContext = {
  state: {
    token: "",
    questions: [||],
    categories: [||],
    quizStream: MakeStream.array(~arrayList=[||]),
    numberOfQuestions: 0,
    quizDifficulty: "any",
    quizType: "any",
    fetchingQuestions: false,
  },
  dispatch: _ => (),
};
let context = React.createContext(quizContext);

let useQuiz = () => React.useContext(context);