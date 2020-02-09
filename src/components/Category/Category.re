[@react.component]
let make = (~category: Types.category) => {
  <div className=CategoryStyles.category>
    <h1
      onClick={_ => ReasonReactRouter.push(string_of_int(category.id))}
      className=CategoryStyles.categoryText>
      {React.string(category.name)}
    </h1>
  </div>;
};