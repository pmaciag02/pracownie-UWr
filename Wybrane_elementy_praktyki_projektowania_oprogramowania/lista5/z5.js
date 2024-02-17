var http = require('https');


function promisedGet(url) {
    return new Promise(function (resolve, reject) {
        http.get(url, res => {
            var buffer = '';
            res
                .on('data', function (data) {
                    buffer += data.toString();
                })
                .on('end', function () {
                    // resolve(buffer);
                    console.log(buffer)
                });
        });
    });
}

promisedGet('https://www.google.pl')
