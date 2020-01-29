type option = {
  value: string,
  label: string,
};

type question = {
  category: string,
  type_: string,
  difficulty: string,
  question: string,
  correctAnswer: string,
  incorretAnswers: list(string),
};

type quizContext = {
  token: string,
  questions: list(question),
};