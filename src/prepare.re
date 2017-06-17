module Prepare = {
  include ReactRe.Component;
  type props = {
    cards: list Card.t,
    turn: int,
    onEnd: ReactEventRe.Mouse.t => unit,
  };
  let name = "Prepare";
  let render {props} =>
    <div className="Prepare">
      <div>
        (ReactRe.stringToElement ("Turn:" ^ (string_of_int (props.turn + 1))))
      </div>
      (ReactRe.listToElement(props.cards |> List.map(
        fun (card:Card.t) => <span key=card.name>(ReactRe.stringToElement ("[" ^ card.name ^ "]"))</span>
      )))
      <div>
        <button onClick=props.onEnd>(ReactRe.stringToElement "Attack")</button>
      </div>
    </div>;
};

include ReactRe.CreateComponent Prepare;

let createElement ::cards ::turn ::onEnd => wrapProps {cards, turn, onEnd};
