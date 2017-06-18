/* http://www.codecodex.com/wiki/Shuffle_an_array#OCaml_:_Array.sort */
let swap arr i j => {
  let temp = arr.(i);
  arr.(i) = arr.(j);
  arr.(j) = temp;
};

let fisher_yates_shuffle arr => {
  let l = Array.length arr;
  for i in (l-1) downto (1) {
    let r = Random.int (i+1);
    swap arr i r;
  };
};
