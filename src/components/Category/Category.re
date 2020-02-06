[@react.component]
let make = (~category: Types.category) => {
  <div>
    <h1
      onClick={_ => ReasonReactRouter.push(string_of_int(category.id))}
      className=CategoryStyles.category>
      {React.string(category.name)}
    </h1>
  </div>;
};