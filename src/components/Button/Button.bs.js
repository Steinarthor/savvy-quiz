// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as ButtonStyles$Savvy from "./ButtonStyles.bs.js";

function Button(Props) {
  var text = Props.text;
  var type_ = Props.type_;
  var onClick = Props.onClick;
  var disabled = Props.disabled;
  return React.createElement("button", {
              className: ButtonStyles$Savvy.button,
              disabled: disabled,
              type: type_,
              onClick: onClick
            }, text);
}

var make = Button;

export {
  make ,
  
}
/* react Not a pure module */
