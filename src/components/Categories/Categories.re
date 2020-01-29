type state =
  | LoadingCategories
  | LoadedCategories(array(APIDecode.Category.t))
  | Error;

let initialState = LoadingCategories;

[@react.component]
let make = (~children: array(APIDecode.Category.t) => React.element) => {
  let (state, setState) = React.useState(() => LoadingCategories);
  React.useEffect0(() => {
    // Fetching categories
    Js.Promise.(
      Fetch.fetch("https://opentdb.com/api_category.php")
      |> then_(Fetch.Response.json)
      |> then_(json => {
           let response = APIDecode.Categories.decode(json);
           setState(_prevState =>
             LoadedCategories(response.trivia_categories)
           );
           resolve();
         })
      |> catch(_err => {
           setState(_prevState => Error);
           Js.Promise.resolve();
         })
      |> ignore
    );

    None;
  });

  switch (state) {
  | LoadingCategories => React.string("Loading Categories")
  | LoadedCategories(categories) => children(categories)
  | Error => React.string("Error")
  };
};