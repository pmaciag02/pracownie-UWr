function memoize(fn) {
var cache = {};
return function(n) {
if ( n in cache ) {
return cache[n]
} else {
var result = fn(n);
cache[n] = result;
return result;
}
}
}




function fibRec(n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

var memFib = memoize(fibRec);

const maxN = 40;

console.time('fibRec')
console.log(fibRec(40))
console.timeEnd('fibRec')

console.time('memFib')
console.log(memFib(40))
console.timeEnd('memFib')

console.time('memFib cache saved')
console.log(memFib(40))
console.timeEnd('memFib cache saved')

