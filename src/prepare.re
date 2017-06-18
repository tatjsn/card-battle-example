let component = ReasonReact.statelessComponent "Prepare";

/* (onEnd: ReactEventRe.Mouse.t => unit) */
let make ::onEnd _children => {
  ...component,
  render: fun () _self => {
    <div className="Prepare">
      <button onClick=onEnd>(ReasonReact.stringToElement "Attack")</button>
    </div>;
  },
};
