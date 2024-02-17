function sum(...args) {
    var result = 0;
    for (var i = 0; i < args.length; i++) {
        result += args[i]
    }
    return result;
}

console.log(sum())
console.log(sum(1, 2, 3))
console.log(sum(1, 2, 3, 4, 5))