[@react.component]
let make =
    (
      ~value: string,
      ~onChange: ReactEvent.Form.t => unit,
      ~type_: string,
      ~isValid: bool,
      ~placeholder: string=?,
      ~required: bool=?,
      ~readOnly: bool=?,
      ~max: string=?,
      (),
    ) => {
  InputStyles.(
    <input
      type_
      value
      onChange
      className={input(isValid)}
      placeholder
      required
      readOnly
      max
    />
  );
};