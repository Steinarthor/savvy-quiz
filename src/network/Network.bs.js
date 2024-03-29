// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE

import * as $$String from "bs-platform/lib/es6/string.js";
import * as Types$Savvy from "../types/Types.bs.js";

function constructUrl(baseUrl, difficulty, quizType) {
  if (difficulty !== "any" && quizType === "any") {
    return $$String.concat("&", /* :: */[
                baseUrl,
                /* :: */[
                  "difficulty=" + difficulty,
                  /* [] */0
                ]
              ]);
  } else if (difficulty !== "any" && quizType !== "any") {
    return $$String.concat("&", /* :: */[
                baseUrl,
                /* :: */[
                  "difficulty=" + difficulty,
                  /* :: */[
                    "type=" + quizType,
                    /* [] */0
                  ]
                ]
              ]);
  } else if (difficulty === "any" && quizType !== "any") {
    return $$String.concat("&", /* :: */[
                baseUrl,
                /* :: */[
                  "type=" + quizType,
                  /* [] */0
                ]
              ]);
  } else {
    return baseUrl;
  }
}

function fetchQuestions(number, categoryId, token, difficulty, quizType) {
  var baseUrl = "https://opentdb.com/api.php?amount=" + (String(number) + ("&category=" + (categoryId + ("&token=" + token))));
  return fetch(constructUrl(baseUrl, difficulty, quizType)).then((function (prim) {
                  return prim.json();
                })).then((function (json) {
                return Promise.resolve(Types$Savvy.CategoryTypeResult.decode(json));
              }));
}

export {
  constructUrl ,
  fetchQuestions ,
  
}
/* No side effect */
