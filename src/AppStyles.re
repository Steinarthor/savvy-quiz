open Css;

let container =
  style([
    display(`flex),
    flexDirection(`column),
    alignItems(`center),
    justifyContent(`center),
  ]);

let form = style([width(px(650))]);