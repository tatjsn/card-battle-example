type attack =
  | Arts
  | Quick
  | Buster;

type t = {
  name: string,
  attacks: list attack,
};

let attackString = fun (att: attack) => switch att {
  | Arts => "Arts"
  | Quick => "Quick"
  | Buster => "Buster"
}
