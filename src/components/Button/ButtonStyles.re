open Css;

let button =
  style([
    height(px(55)),
    width(pct(100.)),
    border(px(0), `none, transparent),
    maxWidth(px(300)),
    margin(px(25)),
    borderRadius(px(4)),
    backgroundColor(Css_AtomicTypes.Color.hex(Colors.lightblue)),
    boxShadows([
      Shadow.box(~y=px(1), ~blur=px(3), rgba(0, 0, 0, 0.12)),
      Shadow.box(~y=px(1), ~blur=px(2), rgba(0, 0, 0, 0.24)),
    ]),
    focus([outline(px(0), `none, transparent)]),
    fontSize(px(16)),
    color(white),
    cursor(`pointer),
  ]);