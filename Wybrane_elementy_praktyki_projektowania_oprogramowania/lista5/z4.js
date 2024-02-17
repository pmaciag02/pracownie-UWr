const fs = require('fs');


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

readPromise('text.txt', 'utf-8')
.then(data => {
    console.log(data);
});

