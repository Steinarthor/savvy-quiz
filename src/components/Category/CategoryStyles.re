open Css;

let category = style([width(pct(50.))]);

let categoryText =
  style([
    width(pct(100.)),
    padding(px(10)),
    textAlign(center),
    cursor(`pointer),
    hover([backgroundColor(Css_AtomicTypes.Color.hex(Colors.red))]),
  ]);