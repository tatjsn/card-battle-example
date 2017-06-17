module Action = {
  include ReactRe.Component;

  type props = {
    cards: list Card.t,
    attacks: list (int, int),
    onSelect: ReactEventRe.Mouse.t => unit,
  };

  let name = "Action";

  let render { props } =>
    <div className="Action">
      (
        ReactRe.listToElement(props.attacks |> List.mapi( /* map with index */
          fun (index: int) (att: (int, int)) => {
            let (cardIndex, attackIndex) = att;
            let card = List.nth props.cards cardIndex;
            let attack = List.nth card.attacks attackIndex;
            <button
             key=((string_of_int index) ^ card.name ^ (Card.attackString attack))
             onClick=props.onSelect
            >(ReactRe.stringToElement ("[" ^ card.name ^ (Card.attackString attack) ^ "]"))</button>
          }
        ))
      )
    </div>;
};

include ReactRe.CreateComponent Action;

let createElement ::cards ::attacks ::onSelect => wrapProps { cards, attacks, onSelect };
