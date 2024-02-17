// function* take(it, top) {
//     let index = 0;
//     while (index <= top) {
//         yield it.next().value;
//         ++index;
//     }
// }

function* take(it, top) {
    for (let i = 0; i < top; i++) {
        yield it.next().value;
    }
}



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

function *fib2(current = 1, next = 1) {
    yield current;
    yield *fib2(next, current + next);

    // let f0 = 0, f1 = 1;
    // while (true) {
    //     yield f0;
    //     [f0, f1] = [f1, f0 + f1];
    // }
}




for (let num of take(fib1(), 10))
    console.log(num);



for (let num of take(fib2(), 10))
    console.log(num);