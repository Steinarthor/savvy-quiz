open Css;

let questions =
  style([
    display(`flex),
    flexDirection(`column),
    alignItems(`center),
    justifyContent(`center),
  ]);

let question =
  style([
    margin(px(5)),
    cursor(`pointer),
    fontSize(px(24)),
    fontWeight(bold),
  ]);