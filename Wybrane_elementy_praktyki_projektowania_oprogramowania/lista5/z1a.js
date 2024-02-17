module.exports = { a };
var modul2 = require('./z1b');

function a(n) {
    if (n > 0) {
        console.log('moduł nr 1');
        modul2.b(n - 1);
    }
}