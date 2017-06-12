module App = {
  include ReactRe.Component.Stateful;
  type screenState =
    | Prepare
    | Action
    | Result;
  let name = "App";
  type props = unit;
  type state = {
    screen: screenState,
    turn: int,
  };
  let getInitialState _ => {
    {
      screen: Prepare,
      turn: 0,
    };
  };
  let handlePrepareEnd {state} _ => {
    Some {...state, screen: Action};
  };
  let handleCardSelect {state} _ => {
    None;
  };
  let render {state, updater} =>
    <div>
    (
      switch state.screen {
        | Prepare => <Prepare
                      turn=state.turn
                      onEnd=(updater handlePrepareEnd)
                      />
        | Action => <Action
                     turn=state.turn
                     onSelect=(updater handleCardSelect)
                     />
        | Result => <div>(ReactRe.stringToElement "Result")</div>
      }
    )
    </div>;
};

include ReactRe.CreateComponent App;

let createElement = wrapProps ();
