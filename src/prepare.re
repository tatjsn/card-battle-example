let component = ReasonReact.statelessComponent "Prepare";

let make onEnd::(onEnd: ReactEventRe.Mouse.t => unit) _children => {
  ...component,
  render: fun () _self => {
    <div className="Prepare">
      <button onClick=onEnd>(ReasonReact.stringToElement "Attack")</button>
    </div>;
  },
};
