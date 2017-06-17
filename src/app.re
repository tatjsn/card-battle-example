module App = {
  include ReactRe.Component.Stateful;

  type screenState =
    | Prepare
    | Action
    | Result;

  let name = "App";

  type props = {
    cards: list Card.t,
  };

  type state = {
    screen: screenState,
    turn: int,
    attacks: list (int, int), /* Index of card, attacks */
  };

  let getInitialState _ => {
    {
      screen: Prepare,
      turn: 0,
      attacks: [],
    };
  };

  let handlePrepareEnd {props, state} _ => {
    Some {
      ...state,
      attacks: [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)], /* TODO: Random this */
      screen: Action,
    };
  };

  let handleCardSelect {state} _ => {
    None;
  };

  let render {props, state, updater} =>
    <div>
      <div>
        (ReactRe.stringToElement ("Turn:" ^ (string_of_int (state.turn + 1))))
      </div>
      (
        ReactRe.listToElement(props.cards |> List.map(
          fun (card: Card.t) => <span key=card.name>(ReactRe.stringToElement ("[" ^ card.name ^ "]"))</span>
        ))
      )
      (
        switch state.screen {
          | Prepare => <Prepare
                        onEnd=(updater handlePrepareEnd)
                       />
          | Action => <Action
                       cards=props.cards
                       attacks=state.attacks
                       onSelect=(updater handleCardSelect)
                      />
          | Result => <div>(ReactRe.stringToElement "Result")</div>
        }
      )
    </div>;
};

include ReactRe.CreateComponent App;

let createElement ::cards => wrapProps { cards: cards };
