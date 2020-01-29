open Css;

let select = {
  style([
    width(pct(100.)),
    height(px(50)),
    margin4(~top=px(5), ~bottom=px(5), ~right=px(0), ~left=px(0)),
    padding(px(20)),
    border(px(1), `solid, Css_AtomicTypes.Color.hex(Colors.gray)),
    borderRadius(px(8)),
    boxShadow(`none),
    fontSize(px(16)),
    focus([outline(px(0), `none, transparent)]),
  ]);
};