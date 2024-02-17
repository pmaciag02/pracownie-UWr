var prime;

for (let i = 2; i <= 100000; i++) {
    prime = true;
    for (let j = 2; j <= Math.sqrt(i); j++) {
        if (!(i % j)) {
            prime = false;
            break;
        }
    }
    if (prime) console.log(i);
}
