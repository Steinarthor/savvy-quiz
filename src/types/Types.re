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

type answer = {
  category: string,
  difficulty: string,
  question: string,
  correctAnswer: string,
  answer: string,
};

type quizAction =
  | SetNumberOfQuestions(int)
  | SetQuizDifficulty(string)
  | SetQuizType(string)
  | SetQuestions(array(question))
  | SetToken(string)
  | MakeStream;

type quizState = {
  token: string,
  questions: array(question),
  quizStream: Stream.t(question),
  numberOfQuestions: int,
  quizDifficulty: string,
  quizType: string,
};

type quizContext = {
  state: quizState,
  dispatch: quizAction => unit,
};

type requestToken = {
  response_code: int,
  response_message: string,
  token: string,
};

type category = {
  id: int,
  name: string,
};

type categoryTypeResults = {
  responseCode: int,
  results: array(question),
};

module RequestToken = {
  type t = requestToken;

  let decode = json => {
    Json.Decode.{
      response_code: json |> field("response_code", int),
      response_message: json |> field("response_message", string),
      token: json |> field("token", string),
    };
  };
};

module Category = {
  type t = category;

  let decode = json => {
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
    };
  };
};

module Categories = {
  type t = {trivia_categories: array(Category.t)};

  let decode = json => {
    Json.Decode.{
      trivia_categories:
        json |> field("trivia_categories", array(Category.decode)),
    };
  };
};

module CategoryType = {
  type t = question;

  let decode = json => {
    Json.Decode.{
      category: json |> field("category", string),
      type_: json |> field("type", string),
      difficulty: json |> field("difficulty", string),
      question: json |> field("question", string),
      correctAnswer: json |> field("correct_answer", string),
      incorretAnswers: json |> field("incorrect_answers", list(string)),
    };
  };
};
module CategoryTypeResult = {
  type t = categoryTypeResults;

  let decode = json => {
    Json.Decode.{
      responseCode: json |> field("response_code", int),
      results: json |> field("results", array(CategoryType.decode)),
    };
  };
};