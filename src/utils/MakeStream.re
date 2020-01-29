let array =
  Stream.(
    (~arrayList: array('a)) => {
      from((i: int) =>
        switch (arrayList[i]) {
        | item => Some(item)
        | exception (Invalid_argument("index out of bounds")) => None
        }
      );
    }
  );