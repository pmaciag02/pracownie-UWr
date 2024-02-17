function digitsSum(number) {
    var sum = 0;
    while (number >= 1) {
        sum += number % 10;
        number = Math.floor(number / 10);

    }
    return sum;
}

function digitsDiv(number) {
    var number2 = number;
    while (number2 >= 1) {
        if (number % (number2 % 10) || !(number2 % 10)) return false;
        number2 = Math.floor(number2 / 10);
    }
    return true;

}

for (let i = 1; i <= 100000; i++) {
    if (digitsDiv(i) && i % digitsSum(i) === 0) {
        console.log(i);
    }
}