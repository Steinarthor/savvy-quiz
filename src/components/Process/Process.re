[@react.component]
let make = (~count: int, ~totalQuestions: int) => {
  let total = float_of_int(count) /. float_of_int(totalQuestions);

  <div className=ProcessStyles.process>
    <span className={ProcessStyles.processBar(total *. 100.)} />
  </div>;
};