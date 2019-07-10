const test = () => {
  // Functions
  const add: (baseValue: number, increment: number) => number = (x, y = 2) => {
    return x + y;
  };
  const optionalAdd: (baseValue: number, increment?: number) => number = (
      x,
      y = 2
  ) => {
    return x + y;
  };
  // Generics
  function identity<T>(arg: T): T {
    return arg;
  }
  let output = identity<string>("myString");
  let output1 = identity("myString");

  function loggingIdentity<T>(arg: T[]): T[] {
    console.log(arg.length); // Array has a .length, so no more error
    return arg;
  }
  function loggingIdentityAlternative<T>(arg: Array<T>): Array<T> {
    console.log(arg.length); // Array has a .length, so no more error
    return arg;
  }

  interface GenericIdentityFn {
    <T>(arg: T): T;
  }

  function identity3<T>(arg: T): T {
    return arg;
  }
};

const UtilityTypes = () => {
  // Partial<T>
  interface Todo {
    title: string,
    desc: string
  }
  function updateTodo(todo: Todo, fieldsToUpd: Partial<Todo>): Todo {
    return Object.assign(todo, fieldsToUpd);
  }
  const todo: Todo = {} as Todo;
  const todo1: Todo = {
    title: "do the hoovering",
    desc: "title is self explanatory."
  };
  // Readonly<T>
  // Record<Page, PageInfo>
  interface PageInfo {
    title: string;
  }

  type Page = 'home' | 'about' | 'contact';

  const x: Record<Page, PageInfo> = {
    about: { title: 'about' },
    contact: { title: 'contact' },
    home: { title: 'home' },
  };
  // Pick<T,K>
  interface Todo_ {
    title: string;
    description: string;
    completed: boolean;
  }

  type TodoPreview = Pick<Todo_, 'title' | 'completed'>;

  const todo2: TodoPreview = {
    title: 'Clean room',
    completed: false,
  };
  // Exclude<T,U>
  type T0 = Exclude<"a" | "b" | "c", "a">;  // "b" | "c"
  type T1 = Exclude<"a" | "b" | "c", "a" | "b">;  // "c"
  type T2 = Exclude<string | number | (() => void), Function>;  // string | number
  // Extract<T,U>
  type T3 = Extract<"a" | "b" | "c", "a" | "f">;  // "a"
  type T4 = Extract<string | number | (() => void), Function>;  // () => void
  // NonNullable<T>
  // Constructs a type by excluding null and undefined from T
  // ReturnType<T>
  // Constructs a type consisting of the return type of function T.
  // Required<T>
  interface Props {
    a?: number;
    b?: string;
  }
  // const obj2: Required<Props> = { a: 5 }; // Error: property 'b' missing


};
