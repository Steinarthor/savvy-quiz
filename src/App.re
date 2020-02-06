[@react.component]
let make = () => {
  <div className=AppStyles.container>
    <Categories>
      {(categoryList: array(Types.category)) =>
         categoryList
         |> Array.map((category: Types.category) =>
              <Category category key={string_of_int(category.id)} />
            )
         |> React.array}
    </Categories>
  </div>;
};