function fibIt(n) {
    var f0 = 0, f1 = 1;
    var f2, temp;
    for(let i = 2; i <= n; i++) {
        temp = f1;
        f1 += f0;
        f0 = temp;
    }

    if(n) {
        return f1;
    }
    else {
        return 0;
    }
}

function fibRec(n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}


const maxN = 40;

for (let n = 10; n <= maxN; n++) {
    console.time(`Iteracja(${n})`);
    fibIt(n);
    console.timeEnd(`Iteracja(${n})`);

    console.time(`Rekurencja(${n})`);
    fibRec(n);
    console.timeEnd(`Rekurencja(${n})`);
}