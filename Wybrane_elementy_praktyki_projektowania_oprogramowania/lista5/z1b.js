module.exports = { b };
var modul1 = require('./z1a');

function b(n) {
    if (n > 0) {
        console.log('moduł nr 2');
        modul1.a(n - 1);
    }
}