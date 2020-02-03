let constructUrl =
  String.(
    (baseUrl: string, difficulty: string, quizType: string) => {
      switch (difficulty, quizType) {
      | (x, y) when x !== "any" && y === "any" =>
        concat("&", [baseUrl, "difficulty=" ++ difficulty])
      | (x, y) when x !== "any" && y !== "any" =>
        concat(
          "&",
          [baseUrl, "difficulty=" ++ difficulty, "type=" ++ quizType],
        )
      | (x, y) when x === "any" && y !== "any" =>
        concat("&", [baseUrl, "type=" ++ quizType])
      | _ => baseUrl
      };
    }
  );

let fetchQuestions = (number, categoryId, token, difficulty, quizType) => {
  let baseUrl =
    "https://opentdb.com/api.php?amount="
    ++ string_of_int(number)
    ++ "&category="
    ++ categoryId
    ++ "&token="
    ++ token;
  Js.Promise.(
    Fetch.fetch(constructUrl(baseUrl, difficulty, quizType))
    |> then_(Fetch.Response.json)
    |> then_(json => Types.CategoryTypeResult.decode(json) |> resolve)
  );
};