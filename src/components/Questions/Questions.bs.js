// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as Stream from "bs-platform/lib/es6/stream.js";
import * as Question$Savvy from "../Question/Question.bs.js";
import * as QuizContext$Savvy from "../../context/QuizContext.bs.js";

function Questions(Props) {
  var match = React.useState((function () {
          return ;
        }));
  var setCurrentQuestion = match[1];
  var quizContext = QuizContext$Savvy.useQuiz(/* () */0);
  var nextQuestion = function (param) {
    var question;
    try {
      question = Stream.next(quizContext[/* state */0][/* quizStream */2]);
    }
    catch (exn){
      if (exn === Stream.Failure) {
        console.log("No questions left");
        return /* () */0;
      } else {
        throw exn;
      }
    }
    return Curry._1(setCurrentQuestion, (function (param) {
                  return question;
                }));
  };
  React.useEffect((function () {
          nextQuestion(/* () */0);
          return ;
        }), /* array */[quizContext[/* state */0][/* quizStream */2]]);
  return React.createElement(Question$Savvy.make, {
              currentQuestion: match[0],
              nextQuestion: nextQuestion
            });
}

var make = Questions;

export {
  make ,
  
}
/* react Not a pure module */
