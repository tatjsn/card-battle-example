type attack =
  | Arts
  | Quick
  | Buster;

type t = {
  name: string,
  attacks: list attack,
}
