[@react.component]
// Create context to hold the token and questions.
let make = () => {
  <Categories>
    {(categoryList: array(Types.category)) =>
       categoryList
       |> Array.map((category: Types.category) =>
            <Category category key={string_of_int(category.id)} />
          )
       |> React.array}
  </Categories>;
};