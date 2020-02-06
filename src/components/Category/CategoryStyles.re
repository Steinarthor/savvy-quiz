open Css;

let category =
  style([
    width(pct(100.)),
    textAlign(center),
    cursor(`pointer),
    hover([backgroundColor(Css_AtomicTypes.Color.hex(Colors.red))]),
  ]);