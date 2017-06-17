let cards: list Card.t = [
  {
    name: "Nobu",
    attacks: [Buster, Buster, Buster, Buster, Buster],
  },
  {
    name: "Okita",
    attacks: [Quick, Quick, Quick, Quick, Quick],
  }
];

ReactDOMRe.renderToElementWithId <App cards=cards /> "root";
