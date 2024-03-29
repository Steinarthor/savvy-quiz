// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as React from "react";
import * as App$Savvy from "./App.bs.js";
import * as ReasonReactRouter from "reason-react/src/ReasonReactRouter.js";
import * as QuizCategory$Savvy from "./views/QuizCategory.bs.js";

function Router(Props) {
  var url = ReasonReactRouter.useUrl(undefined, /* () */0);
  var match = url[/* path */0];
  if (match) {
    switch (match[0]) {
      case "10" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Books",
                        categoryId: "10"
                      });
          }
          break;
      case "11" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Film",
                        categoryId: "11"
                      });
          }
          break;
      case "12" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Music",
                        categoryId: "12"
                      });
          }
          break;
      case "13" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Musicals and Theatres",
                        categoryId: "13"
                      });
          }
          break;
      case "14" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Television",
                        categoryId: "14"
                      });
          }
          break;
      case "15" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Video Games",
                        categoryId: "15"
                      });
          }
          break;
      case "16" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Board Games",
                        categoryId: "16"
                      });
          }
          break;
      case "17" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Science & Nature",
                        categoryId: "17"
                      });
          }
          break;
      case "18" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Science: Computers",
                        categoryId: "18"
                      });
          }
          break;
      case "19" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Science: Mathematics",
                        categoryId: "19"
                      });
          }
          break;
      case "20" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Mythology",
                        categoryId: "20"
                      });
          }
          break;
      case "21" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Sports",
                        categoryId: "21"
                      });
          }
          break;
      case "22" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Geography",
                        categoryId: "22"
                      });
          }
          break;
      case "23" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "History",
                        categoryId: "23"
                      });
          }
          break;
      case "24" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Politics",
                        categoryId: "24"
                      });
          }
          break;
      case "25" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Art",
                        categoryId: "25"
                      });
          }
          break;
      case "26" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Celebrities",
                        categoryId: "26"
                      });
          }
          break;
      case "27" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Animals",
                        categoryId: "27"
                      });
          }
          break;
      case "28" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Vehicles",
                        categoryId: "28"
                      });
          }
          break;
      case "29" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Entertainment: Comics",
                        categoryId: "29"
                      });
          }
          break;
      case "30" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Science: Gadgets",
                        categoryId: "30"
                      });
          }
          break;
      case "31" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Entertainment: Japanese Anime & Manga",
                        categoryId: "31"
                      });
          }
          break;
      case "32" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "Entertainment: Cartoon & Animations",
                        categoryId: "32"
                      });
          }
          break;
      case "9" :
          if (!match[1]) {
            return React.createElement(QuizCategory$Savvy.make, {
                        title: "General",
                        categoryId: "9"
                      });
          }
          break;
      default:
        
    }
  }
  return React.createElement(App$Savvy.make, { });
}

var make = Router;

export {
  make ,
  
}
/* react Not a pure module */
