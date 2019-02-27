//----- Reading Constructor Method
class Foo {
    static get [Symbol.species]() {
        return this;
    }
    spawn() {
        return new this.constructor[Symbol.species]();
    }
}
class Bar extends Foo {
    static get [Symbol.species]() {
        return Foo;
    }
}
let a = new Foo();
let b = a.spawn();
let x = new Bar();
let y = x.spawn();
console.log(b instanceof Foo); //true
console.log(y instanceof Bar); //false
console.log(y instanceof Foo); //true
//----- Changing Constructor
class World {
    constructor(word) {
        this.word = word;
    }
}
Object.defineProperty(World, Symbol.hasInstance, {
    value: function(obj) {
        return obj.word == "icecream";
    }
})
let a = new World("icecream");
let b = new World();
a instanceof World; // true
b instanceof World; // false
//----- Changing Stringify
class Parol {}
let b = new Parol;
b[Symbol.toStringTag] = "Cool";
b.toString(); // [object Cool];
//----- Making unConcatable
array[Symbol.isConcatSpreadable] = boolean;
//----- Making Primitive
let arr = [1,2,3,4,5];
arr[Symbol.toPrimitive] = function(hint) {
    return this.reduce((acc,cur) => acc+cur, 0);
};
console.log(arr + 10); // 25
//----- Proxy
let obj = { a: 1 },
    handlers = {
        get(target, key, context) {
            console.log(`accessing: ${key}`);
            return Reflect.get(
                target, key, context
            );
        }
    },
    pobj = new Proxy(obj, handlers);
    obj.a;
    pobj.a
//----- Revocable Proxy
let obj = { a: 1 },
    handlers = {
        get(target, key, context) {
            console.log(`accessing: ${key}`);
            return target[key];
        }
    },
    { proxy: pobj, revoke: prevoke } = Proxy.revocable(obj, handlers);
    pobj.a
    prevoke();
//----- Iterator
let array = [1, 2, 3];
it = array[Symbol.iterator]();
it.next();
//----- Generators
function *generator() {
    let arr = [ yield 1, yield 2, yield 3];

}
function *additional() {
    yield *[1,2,3];
}
for (let v of additional()) {
    console.log(v);
}
//----- User Iterator
let Fib = {
    [Symbol.iterator]() {
        let n1 = 1, n2 = 1, current;
        return {
            [Symbol.iterator]() {
                return this;
            },
            next() {
                current = n2;
                n2 = n1;
                n1 = n1 + current;
                if (a > 200) return { value: current, done: true };
                return { value: current, done: false};
            },
            return(v) {
                console.log("Последовательность завершена.");
                return { value: v, done: true };
            }
        };
    }
};
for (let v of Fib) {
    console.log(v);
}
//----- Destructuring and Restructuring
function foo() {
    return [1, 2, 3];
}
function bar() {
    return { x: 4, y: 5 , z: 6 };
}
function futu() {
    let [a, b, c] = foo();
    let { x: var1, y: var2, z: var3 } = bar();
    console.log(a, b, c); // 1, 2, 3
    console.log(var1, var2, var3); // 4, 5, 6
}
//
let defaults = {
    options: {
        remove: true,
        enable: false,
        instance: {}
    },
    log: {
        warn: true,
        error: true
    }
};
let config = {
    options: {
        remove: false,
        instance: null
    }
};
let {
    options: {
        remove = defaults.options.remove,
        enable = defaults.options.enable,
        instance = defaults.options.instance
    } = {},
    log: {
        warn = defaults.log.warn,
        error = defaults.log.error
    } = {},
} = config;
config = {
    options: {
        remove,
        enable,
        instance
    },
    log: {
        warn,
        error
    }
};
//----- Promises
let promise = new Promise((res, rej) => {
    setTimeout(() => {
        res("result");
    }, 1000);
    // rej('reason'); -- "throws" reason error
});
promise.then(
        result => {
            alert("Fulfilled: " + result);
        },
        error => {
            alert("Rejected: " + error);
        }
    );
//--
function ajax(url) {
    return new Promise( function pr(resolve, reject){
        //
    });
}
ajax("https://server.com/1.php").then(
    function fulfilled(contents){

    },
    function rejected(reason){

    }
);
//-- Parsing data from promise
let obj = {
    id: 1,
    name: "Jordan"
}
let promise = new Promise((resolve, reject) => {
    resolve(obj);
});
promise
    .then( data => {
        console.log(data.id); // 1
    }
    );
//-- Paralell use of promises
let obj = {
    id: 1,
    name: "Jordan"
}
let promise = new Promise((resolve, reject) => {
    resolve(obj);
});
let promise2 = new Promise((resolve, reject) => {
    resolve(1);
})

function promisesToProcess() {
    return [...arguments];
}
Promise.all(promisesToProcess(promise, promise2)).then(result => {
    console.log(result); // result — array of promises' results
});
Promise.race(promisesToProcess(promise, promise2)).then(result => {
    console.log(result); // result - result of first resolved promise
});
Promise.resolve(value); // creates successfully resolved promise with value result
Promise.reject(error); // creates rejected promise with error error
//----- String.prototype.padStart();
"def".padStart(6, "abc"); // abcdef
"23".padEnd(4, "0"); // '2300'
//----- Array.from()
let arrLike = {
    length: 4,
    2: "hello"
}
Array.from(arrLike); // [undefined, undefined, "hello", undefined];
Array.from(arrLike, (val, i) => {
    if (typeof val == "string") return val.toUpperCase();
    return i;
}); // [0,1,"HELLO",3];
//-- Array.prototype.find
let array = [1,2,3,4,5];
let points = [{ x: 10, y: 20 },{ x: 30, y: 40 },{ x: 40, y: 50 }];
array.find(v => v == "2"); // finds v, otherwise returns undefined
points.find(arg => (arg.x % 3 == 0 && arg.y % 4 == 0)); // { x: 30, y: 40}
//-- Array.prototype.copyWithin(target,start,end)
[1,2,3,4,5].copyWithin(3,0); // [1,2,3,1,2]
[1,2,3,4,5].copyWithin(0,3,5); // [4,5,3,4,5]
//----- eval(), blur(), focus();
eval("console.log('Hello world!')"); // 'Hello world!'
node.focus(); // adds focus on input/textarea
node.blur(); //  removes focus from input/textarea
//----- Symbol as object defineProperty
let object = {
    [Symbol("bar")]: 21, // not enumerable
}
//----- Labels
Labels can be assigned to for loops or blocks of code (loop1: {});
continue loop1, break loop1; // used to whether continue loop1 or break it
//----- Import/Export
export function foo(){}; // exports foo
export class Hello {}; // exports Hello class
export { foo, Hello }; // exports both of them
export default function foo(){}; // exports foo as default
export { foo as default, Hello }; //exports foo as default, Hello
export { foo, Hello } from "./baz"; // exports foo and Hello, exported from 'baz' module
import { foo, bar } from "./baz"; //
import { foo as bar } from "./baz";
// if module has just default export results the following syntax is appropriate:
import foo from "./baz"; // imports foo(foo == default)
import { default as bar } from "./baz";
// unified syntax:
import foo /* which is default */, { bar, baz } from "./baz";
// import the entire module's API
import * as foo from "foo"; // foo.bar(), foo.baz()
//----- Fetch API
// https://developer.mozilla.org/ru/docs/Web/API/Fetch_API/Using_Fetch
 const promise = fetch(url).then(res => res.json());
