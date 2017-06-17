module Prepare = {
  include ReactRe.Component;
  type props = {
    onEnd: ReactEventRe.Mouse.t => unit,
  };
  let name = "Prepare";
  let render { props } =>
    <div className="Prepare">
      <button onClick=props.onEnd>(ReactRe.stringToElement "Attack")</button>
    </div>;
};

include ReactRe.CreateComponent Prepare;

let createElement ::onEnd => wrapProps { onEnd: onEnd };
