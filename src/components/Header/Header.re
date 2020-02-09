[@react.component]
let make = () => {
  <header className=HeaderStyles.header>
    <h2
      className=HeaderStyles.headerTitle
      onClick={_ => ReasonReactRouter.push("/")}>
      {React.string("Savvy")}
    </h2>
  </header>;
};