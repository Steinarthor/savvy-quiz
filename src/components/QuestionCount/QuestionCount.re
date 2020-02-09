[@react.component]
let make = (~count: int, ~total: int) => {
  <div>
    <p>
      {React.string(
         "Question"
         ++ " "
         ++ string_of_int(count)
         ++ " "
         ++ "/"
         ++ " "
         ++ string_of_int(total),
       )}
    </p>
  </div>;
};