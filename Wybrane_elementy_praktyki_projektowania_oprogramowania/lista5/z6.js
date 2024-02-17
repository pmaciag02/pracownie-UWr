const readline = require('readline');
const fs = require('fs');

var results = {};


var a = readline.createInterface({
    input: fs.createReadStream('logs.txt')
});

for await ( var line of a ) {
    
}

a.on('line', function (line) {
    var ip = line.split(" ")[1];
    results[ip] = (results[ip] || 0) + 1
});


a.on('close', function () {

    // console.log(Object.entries(results))
    
    const sortedIPs = Array.from(Object.entries(results)).sort((a, b) => b[1] - a[1]);

    for (let i = 0; i < 3; i++) {
        console.log(sortedIPs[i]);
    }
});