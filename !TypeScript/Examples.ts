let c: Set<string> = new Set(["string"]);

interface Action {
  readonly type: string;
  readonly data: object;
  readonly error?: boolean;
  readonly [propName: string]: any;
}
// function types
interface Reducer {
  (state: object, action: Action): object;
}
const reducer: Reducer = (state = {}, action) => {
  if (action.type === "GET_USER") {
    return { ...state, ...action };
  }
  return {};
};
// interface NumberDictionary {
//    readonly [state: string]: boolean;
// }

// constructor example
// interface ClockConstructor {
//     new (hour: number, minute: number): ClockInterface;
// }
// interface ClockInterface {
//     tick(): void;
// }
//
// function createClock(ctor: ClockConstructor, hour: number, minute: number): ClockInterface {
//     return new ctor(hour, minute);
// }
//
// class DigitalClock implements ClockInterface {
//     constructor(h: number, m: number) { }
//     tick() {
//         console.log("beep beep");
//     }
// }
// class AnalogClock implements ClockInterface {
//     constructor(h: number, m: number) { }
//     tick() {
//         console.log("tick tock");
//     }
// }
//
// let digital = createClock(DigitalClock, 12, 17);
// let analog = createClock(AnalogClock, 7, 32);

// interface extends
interface Shape {
  color: string;
}
interface Stroke extends Shape {
  width: number;
}
interface Square extends Stroke {
  length: number;
}
const square: Square = {} as Square;
square.width = 123;