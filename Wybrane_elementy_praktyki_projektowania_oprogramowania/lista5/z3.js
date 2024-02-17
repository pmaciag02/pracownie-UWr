var readline = require('readline');

ans = Math.floor(Math.random() * 101);
console.log(ans)

var rl = readline.createInterface(process.stdin, process.stdout);

rl.setPrompt('Zgdanij liczbę od 0 do 100: ');

rl.prompt();

rl.setPrompt('Źle. Zgadnij ponownie: ');

rl
    .on('line', function(line) {
        if (parseInt(line) === ans) {
            rl.close();
        }
        else {
            rl.prompt();
        }
    })
    .on('close',function(){
        console.log("Zgadłeś!")
        process.exit(0);
    });