[@react.component]
// Create context to hold the token and questions.
let make = () => {
  <Categories>
    {(categoryList: array(APIDecode.Category.t)) =>
       categoryList
       |> Array.map((category: APIDecode.Category.t) =>
            <Category category key={string_of_int(category.id)} />
          )
       |> React.array}
  </Categories>;
};