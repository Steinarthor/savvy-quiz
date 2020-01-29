[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["9"] => <QuizCategory title="General" categoryId="9" />
  | ["10"] => <QuizCategory title="Books" categoryId="10" />
  | ["11"] => <QuizCategory title="Film" categoryId="11" />
  | ["12"] => <QuizCategory title="Music" categoryId="12" />
  | ["13"] => <QuizCategory title="Musicals and Theatres" categoryId="13" />
  | ["14"] => <QuizCategory title="Television" categoryId="14" />
  | ["15"] => <QuizCategory title="Video Games" categoryId="15" />
  | ["16"] => <QuizCategory title="Board Games" categoryId="16" />
  | ["17"] => <QuizCategory title="Science & Nature" categoryId="17" />
  | ["18"] => <QuizCategory title="Science: Computers" categoryId="18" />
  | ["19"] => <QuizCategory title="Science: Mathematics" categoryId="19" />
  | ["20"] => <QuizCategory title="Mythology" categoryId="20" />
  | ["21"] => <QuizCategory title="Sports" categoryId="21" />
  | ["22"] => <QuizCategory title="Geography" categoryId="22" />
  | ["23"] => <QuizCategory title="History" categoryId="23" />
  | ["24"] => <QuizCategory title="Politics" categoryId="24" />
  | ["25"] => <QuizCategory title="Art" categoryId="25" />
  | ["26"] => <QuizCategory title="Celebrities" categoryId="26" />
  | ["27"] => <QuizCategory title="Animals" categoryId="27" />
  | ["28"] => <QuizCategory title="Vehicles" categoryId="28" />
  | ["29"] => <QuizCategory title="Entertainment: Comics" categoryId="29" />
  | ["30"] => <QuizCategory title="Science: Gadgets" categoryId="30" />
  | ["31"] =>
    <QuizCategory
      title="Entertainment: Japanese Anime & Manga"
      categoryId="31"
    />
  | ["32"] =>
    <QuizCategory
      title="Entertainment: Cartoon & Animations"
      categoryId="32"
    />
  | _ => <App />
  };
};