const fs   = require('fs');
const util = require('util');

// Normalna funkcja wykorzystująca fs::readFile
fs.readFile('text.txt', 'utf-8', function(err, data) {
    console.log("fs::readFile:\n" + data);
});






// za pomocą ”ręcznie” napisanej funkcji przyjmującej te same argumenty co fs::readFile, ale zwracającej Promise
function readPromise(path, encoding) {
    return new Promise((resolve, reject) => {
        fs.readFile(path, encoding, (err, data) => {
            if (err) {
                console.log(err);
                reject(err);
            }
            resolve(data);
        })
    })
};

// ”po staremu” - wywołanie z kontynuacją (Promise::then)
readPromise('text.txt', 'utf-8')
.then((data) => {
    console.log("readPromise then:\n" + data)
});

// ”po nowemu” - wywołanie przez async/await
(async function() {
    var data = await readPromise('text.txt', 'utf-8');
    console.log("readPromise await:\n" + data);
})();








// za pomocą util.promisify z biblioteki standardowej
const readFileAsync = util.promisify(fs.readFile);

readFileAsync('text.txt', 'utf-8')
.then(data => {
    console.log("util.promisify:\n" + data);
});





// za pomocą fs.promises z biblioteki standardowej
fs.promises.readFile('text.txt', 'utf-8')
.then(data => {
    console.log("fs.promises:\n" + data);
});



