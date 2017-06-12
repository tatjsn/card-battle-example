module Prepare = {
  include ReactRe.Component;
  type props = {
    turn: int,
    onEnd: ReactEventRe.Mouse.t => unit,
  };
  let name = "Prepare";
  let render {props} =>
    <div className="Prepare">
      <div>
        (ReactRe.stringToElement ("Turn:" ^ (string_of_int (props.turn + 1))))
      </div>
      <div>
        <button onClick=props.onEnd>(ReactRe.stringToElement "Attack")</button>
      </div>
    </div>;
};

include ReactRe.CreateComponent Prepare;

let createElement ::turn ::onEnd => wrapProps {turn, onEnd};
