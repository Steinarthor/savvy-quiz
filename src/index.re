// Global Css Styles
open Css;
let globalFont =
  fontFace(
    ~fontFamily="MontserratMedium",
    ~src=[url("./src/fonts/Montserrat-Light.otf")],
    (),
  );
global(
  "html",
  [
    boxSizing(borderBox),
    selector(
      "*, *:before, *:after",
      [boxSizing(inherit_), fontFamily(globalFont)],
    ),
  ],
);
global(
  "body",
  [
    fontFamily(globalFont),
    margin(px(0)),
    color(white),
    backgroundColor(Css_AtomicTypes.Color.hex(Colors.indigo)),
  ],
);
global("#app", [margin(px(25))]);
ReactDOMRe.renderToElementWithId(<Root />, "app");