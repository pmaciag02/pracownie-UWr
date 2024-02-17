function getLastProto(o) {
    var p = o;
    do {
        o = p;
        p = Object.getPrototypeOf(o);
    } while (p);
    return o;
}


// Tworzymy kilka obiektów
let obj1 = {};
let obj2 = {};
let obj3 = {};

// Pobieramy ostatni prototyp dla każdego obiektu
let lastProto1 = getLastProto(obj1);
let lastProto2 = getLastProto(obj2);
let lastProto3 = getLastProto(obj3);

// Sprawdzamy czy referencje są identyczne
console.log(lastProto1 === lastProto2); // true
console.log(lastProto2 === lastProto3); // true
console.log(lastProto1 === lastProto3); // true