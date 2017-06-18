type screenState =
  | Prepare
  | Action
  | Result;

type state = {
  screen: screenState,
  turn: int,
  attacks: list (int, int), /* Index of card, attacks */
};

let component = ReasonReact.statefulComponent "App";

let make cards::(cards: list Card.t) _children => {
  let handlePrepareEnd _event state _self => ReasonReact.Update {
    ...state,
    attacks: [(0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2)], /* TODO: Random this */
    screen: Action,
  };

  let handleCardSelect _event _state _self => ReasonReact.NoUpdate;

  {
    ...component,
    initialState: fun () =>  {
      screen: Prepare,
      turn: 0,
      attacks: [],
    },
    render: fun state self => {
      <div>
        <div>
          (ReasonReact.stringToElement ("Turn:" ^ (string_of_int (state.turn + 1))))
        </div>
        (
          ReasonReact.arrayToElement(Array.of_list (cards |> List.map(
            fun (card: Card.t) => <span key=card.name>(ReasonReact.stringToElement ("[" ^ card.name ^ "]"))</span>
          )))
        )
        (
          switch state.screen {
            | Prepare => <Prepare
                          onEnd=(self.update handlePrepareEnd)
                         />
            | Action => <Action
                         cards=cards
                         attacks=state.attacks
                         onSelect=(self.update handleCardSelect)
                        />
            | Result => <div>(ReasonReact.stringToElement "Result")</div>
          }
        )
        </div>;
    },
  };
};
