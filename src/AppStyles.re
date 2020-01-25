open Css;

let container =
  style([
    display(`flex),
    flexDirection(`column),
    alignItems(`center),
    justifyContent(`center),
    height(vh(100.0)),
  ]);

let form = style([width(px(650))]);