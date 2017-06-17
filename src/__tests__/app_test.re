open Jest;
open ExpectJs;

let cards: list Card.t = [
  { name: "Card1", attacks: [Buster] },
];

let _ =

describe "src/app.re" (fun _ => {

  test "is defined" (fun _ => {
    let component = ReactShallowRenderer.renderWithRenderer <App cards=cards />;
    expect (Js.Undefined.return component) |> toBeDefined;
  });

  test "renders" (fun _ => {
    let tree = App.createElement cards::cards children::[] ()
      |> ReactShallowRenderer.renderWithRenderer;

    expect tree |> toMatchSnapshot;
  });

});
