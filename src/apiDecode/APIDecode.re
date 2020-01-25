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
  type t = {trivia_categories: list(Category.t)};

  let decode = json => {
    Json.Decode.{
      trivia_categories:
        json |> field("trivia_categories", list(Category.decode)),
    };
  };
};