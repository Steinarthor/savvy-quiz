open Css;

let container =
  style([
    display(`flex),
    flexWrap(`wrap),
    alignItems(`center),
    justifyContent(`center),
  ]);

let form = style([width(px(650))]);