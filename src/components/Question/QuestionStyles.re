open Css;

let questionText = style([textAlign(center)]);

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
    padding(px(25)),
    width(pct(100.)),
    cursor(`pointer),
    border(px(2), solid, Css_AtomicTypes.Color.hex(Colors.lightblue)),
    borderRadius(px(10)),
    textAlign(center),
    fontSize(px(24)),
    fontWeight(bold),
    hover([
      backgroundColor(Css_AtomicTypes.Color.hex(Colors.darkerIndigo)),
    ]),
  ]);

let selectedQuestion =
  style([
    margin(px(5)),
    padding(px(25)),
    width(pct(100.)),
    cursor(`pointer),
    border(px(2), solid, Css_AtomicTypes.Color.hex(Colors.red)),
    borderRadius(px(10)),
    textAlign(center),
    fontSize(px(24)),
    fontWeight(bold),
  ]);

let correctQuestion =
  style([
    margin(px(5)),
    padding(px(25)),
    width(pct(100.)),
    cursor(`pointer),
    border(px(2), solid, green),
    borderRadius(px(10)),
    textAlign(center),
    fontSize(px(24)),
    fontWeight(bold),
  ]);