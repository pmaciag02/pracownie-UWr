var n = 1;
// liczba ma prototyp?
console.log( typeof Object.getPrototypeOf( n ) );
// można jej dopisać pole/funkcję?
n.foo = 'foo';
console.log( n.foo );