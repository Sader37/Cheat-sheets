// ----- Arrays
const array = [];
Array.isArray();
Array.of();
Array.from();
array.split();
array.join();
array.indexOf();
array.slice();
array.concat();
array.push();
array.pop();
array.shift();
array.unshift();
array.splice();
array.forEach();
arr.filter();
arr.map();
arr.every();
arr.some();
arr.reduce();
arr.reduceRight();
arr.find();
arr.findIndex();
arr.copyWithin(target, start, end);
arr.includes();
arr.sort();
// ----- Strings
const string = "";
string.startsWith();
string.endsWith();
string.includes();
string.repeat();
string.charAt();
string.indexOf();
string.lastIndexOf();
string.concat(separator, [...args]);
string.slice();
string.substr();
string.padStart(int, string);
string.endStart(int, string);
// ----- Numbers
parseInt();
parseFloat();
number.toFixed();
number.toPrecision();
Number.isNaN();
Number.isFinite();
Number.isInteger();
Number.isSafeInteger();
// ----- JSON
JSON.parse(json, callback);     // callback(key, value)
JSON.stringify(obj, callback);  // callback(key, value)
// ----- Object
object.toString();
object.valueOf();
object.hasOwnProperty();
object.getOwnPropertyDescriptors();
Object.keys(object);
Object.values(object);
Object.entries(object);
Object.is(object, object2);
Object.assign(object2, object);
// ----- Maps
const map = new Map();
map.set(key, value);
map.get(key);
map.delete(key);
map.clear();
map.size;
map.has(key);
const wmap = new WeakMap(); // no size(), clear() and isn't iterable
wm.set(key, value); // key is object, if key == null, then y becomes null.
// ----- Sets
const set = new Set();
set.add(value);
set.delete(value);
set.has(value);
set.clear();
set.size;
const wset = new WeakSet();
// ----- Descriptors
const descriptor = {
    value: value,
    writable: boolean,
    configurable: boolean, // property is deletable and changeable
    enumerable: boolean, // visible for iterators
}
Object.defineProperty(object, "property", descriptor);
// ----- Proxy
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
const Fib = {
    [Symbol.iterator]: () => {
        let n1 = 1, n2 = 1, current;
        return {
            [Symbol.iterator]() {
                return this;
            },
            next() {
                current = n2;
                n2 = n1;
                n1 = n1 + current;
                if (current > 150) {
                    console.log("Over.");
                    return { value: current, done: true};
                }
                return { value: current, done: false};
            },
            return(v) {
                console.log("Over.");
                return { value: v, done: true };
            }
        }
    }
};
//----- Promises
const promise = new Promise((res, rej) => {});
//-- Paralell use of Promises
Promise.all(promise, promise2).then(result => {
    console.log(result); // result — array of promises' results
});
Promise.race(promise, promise2).then(result => {
    console.log(result); // result - result of first resolved promise
});
//----- blur(), focus();
node.focus(); // adds focus on input/textarea
node.blur(); //  removes focus from input/textarea
//----- Labels
Labels can be assigned to for loops or blocks of code (loop1: {});
continue loop1, break loop1; // used to whether continue loop1 or break it
//----- Import/Export
import { foo as bar } from "./baz";
import { default as bar } from "./baz";
import * as foo from "foo"; // foo.bar(), foo.baz()