[@react.component]
let make = (~options: list(Types.option), ~onChange: string => unit) => {
  SelectStyles.(
    <select
      className=select
      onChange={event => ReactEvent.Form.target(event)##value->onChange}>
      {options
       |> List.map((option: Types.option) =>
            <option key={option.value} value={option.value}>
              {React.string(option.label)}
            </option>
          )
       |> Array.of_list
       |> React.array}
    </select>
  );
};