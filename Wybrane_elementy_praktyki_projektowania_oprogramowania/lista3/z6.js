function fib1() {
    var f0 = 0;
    var f1 = 1;

    return {
        next: function() {
            [f0, f1] = [f1, f0 + f1];
            return {
                value: f0,
                done: false
            };
        }
    };
}

var fibIterator = fib1();

for (let i = 0; i < 10; i++) {
    console.log(fibIterator.next().value);
}

var _it = fib1();
for ( var _result; _result = _it.next(), !_result.done; ) {
console.log( _result.value );
}


function *fib2(current = 1, next = 1) {
    yield current;
    yield *fib2(next, current + next);

    // let f0 = 0, f1 = 1;
    // while (true) {
    //     yield f0;
    //     [f0, f1] = [f1, f0 + f1];
    // }
}



var n = 40;




for (var i of fib2()) {
    if (i <= n)
        console.log(i);
    else
        return;
}

