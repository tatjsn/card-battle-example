module Action = {
  include ReactRe.Component;
  type props = {
    turn: int,
    onSelect: ReactEventRe.Mouse.t => unit,
  };
  let name = "Action";
  let render {props} =>
    <div className="Action">
      <div>
        (ReactRe.stringToElement ("Turn:" ^ (string_of_int (props.turn + 1))))
      </div>
      <div>
        <button onClick=props.onSelect>(ReactRe.stringToElement "Select1")</button>
        <button onClick=props.onSelect>(ReactRe.stringToElement "Select2")</button>
        <button onClick=props.onSelect>(ReactRe.stringToElement "Select3")</button>
      </div>
    </div>;
};

include ReactRe.CreateComponent Action;

let createElement ::turn ::onSelect => wrapProps {turn, onSelect};
