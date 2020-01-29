let make = React.Context.provider(QuizContext.context);

let makeProps = (~value, ~children, ()) => {
  "value": value,
  "children": children,
};