[@react.component]
let make = () => {
  <Categories>
    {(categoryList: list(APIDecode.Category.t)) =>
       categoryList
       |> List.map((category: APIDecode.Category.t) =>
            <Category category key={string_of_int(category.id)} />
          )
       |> Array.of_list
       |> React.array}
  </Categories>;
};