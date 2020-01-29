let quizContext: Types.quizContext = {token: "", questions: []};
let context = React.createContext(quizContext);

let useQuiz = () => React.useContext(context);