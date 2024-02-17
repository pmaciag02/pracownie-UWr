// process.stdout.write("Podaj swoje imię: ");

// process.stdout.on('data', function(data) {
//     process.stdout.write("Witaj " + data);
//     process.exit();
// })

// process.on('exit', function() {
//     process.stdout.write("Do zobaczenia!\n");
// })

const stdin = process.openStdin()

process.stdout.write('Podaj imię: ')

stdin.addListener('data', text => {
  const name = text.toString().trim()
  console.log('Witaj: ' + name)

  stdin.pause()
})