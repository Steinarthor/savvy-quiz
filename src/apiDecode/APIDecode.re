module RequestToken = {
  type t = {
    response_code: int,
    response_message: string,
    token: string,
  };

  let decode = json => {
    Json.Decode.{
      response_code: json |> field("response_code", int),
      response_message: json |> field("response_message", string),
      token: json |> field("token", string),
    };
  };
};

module Category = {
  type t = {
    id: int,
    name: string,
  };

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
  type t = {
    category: string,
    type_: string,
    difficulty: string,
    question: string,
    correctAnswer: string,
    incorretAnswers: list(string),
  };

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
  type t = {
    responseCode: int,
    results: array(CategoryType.t),
  };

  let decode = json => {
    Json.Decode.{
      responseCode: json |> field("response_code", int),
      results: json |> field("results", array(CategoryType.decode)),
    };
  };
};