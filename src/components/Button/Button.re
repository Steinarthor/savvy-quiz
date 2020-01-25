[@react.component]
let make =
    (
      ~text: string,
      ~type_: string,
      ~onClick: ReactEvent.Mouse.t => unit,
      ~disabled: bool,
    ) => {
  ButtonStyles.(
    <button type_ onClick disabled className=button>
      {React.string(text)}
    </button>
  );
};