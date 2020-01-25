[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["general"] => <General />
  | _ => <App />
  };
};