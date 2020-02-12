[@react.component]
let make = () => {
  let (count, setCount) = React.useState(_ => 1);

  let updateCounter = () => {
    setCount(state => state + 1);
  };

  let timer = Js.Global.setInterval(updateCounter, 1000);

  React.useEffect1(
    () => {
      if (count >= 5) {
        Js.Global.clearInterval(timer);
      };
      Some(() => Js.Global.clearInterval(timer));
    },
    [|count|],
  );

  <div> {React.string("Counter" ++ " " ++ string_of_int(count))} </div>;
};