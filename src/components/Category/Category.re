[@react.component]
let make = (~category: APIDecode.Category.t) => {
  <div className=CategoryStyles.category>
    <h1 onClick={_ => ReasonReactRouter.push("/general")}>
      {React.string(category.name)}
    </h1>
  </div>;
};