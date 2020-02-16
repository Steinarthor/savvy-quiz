open Css;

let process =
  style([
    width(pct(100.)),
    height(px(50)),
    border(px(2), solid, Css_AtomicTypes.Color.hex(Colors.lightblue)),
    borderRadius(px(10)),
  ]);

let processBar = processStatus =>
  style([
    display(inlineBlock),
    width(pct(processStatus)),
    height(pct(100.)),
    borderRadius(px(8)),
    backgroundColor(Css_AtomicTypes.Color.hex(Colors.darkerIndigo)),
    transition(~duration=200, ~delay=0, ~timingFunction=easeInOut, "width"),
  ]);