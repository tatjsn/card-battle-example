let component = ReasonReact.statelessComponent "Action";

let make
  cards::(cards: list Card.t)
  attacks::(attacks: list (int, int))
  onSelect::(onSelect: ReactEventRe.Mouse.t => unit)
  _children => {
    ...component,
    render: fun () _self =>
      <div className="Action">
        (
          ReactRe.listToElement(attacks |> List.mapi( /* map with index */
            fun (index: int) (att: (int, int)) => {
              let (cardIndex, attackIndex) = att;
              let card = List.nth cards cardIndex;
              let attack = List.nth card.attacks attackIndex;
              <button
               key=((string_of_int index) ^ card.name ^ (Card.attackString attack))
               onClick=onSelect
              >(ReactRe.stringToElement ("[" ^ card.name ^ (Card.attackString attack) ^ "]"))</button>
            }
          ))
        )
      </div>,
  };
