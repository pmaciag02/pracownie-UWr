function parametr(n) {
    return function createGenerator() {
        var _state = 0;
        return {
            next: function() {
                return {
                    value: _state,
                    done: _state++ >= n
                };
            }
        };
    };
}

var foo1 = {[Symbol.iterator]: parametr(3)};

var foo2 = {[Symbol.iterator]: parametr(5)};


for (var f of foo1)
    console.log(f);

console.log();

for (var f of foo2)
    console.log(f);