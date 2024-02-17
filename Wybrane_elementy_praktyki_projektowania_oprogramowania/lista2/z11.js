// Dla liczby i stringa przechowujacego sama liczbe
// wszystko jest ok, tzn. dostaniemy sie do elementu,
// do ktorego chcielismy sie dostac. Jak argumentem
// jest inny obiekt, to zwróci nam wartość undefined.
console.log(tab[2])
console.log(tab['2'])
console.log(tab[example]) // undefined
console.log(tab['example.x']) // undefined
console.log(tab[example.x]) // to zadziala

// Po dopisaniu wartości o kluczu niebędącego liczbą
// dopisany zostanie kolejny element na koniec tablicy 
tab[10] = 5
tab['xd'] = 10
tab['dx'] = 15
console.log(tab[5]) // tu nie ma zadnego elementu
console.log(tab['xd'])
console.log(tab[10])
console.log(tab)

// Uzycie [] sprawia, ze wyrazenie jest ewaluowane,
// a nastepnie uzywane, tzn. dla x[prop] oraz
// prop = a otrzymamy x.a, dla prop = b bedzie x.b
// Uzycie . sprawia, ze wyrazenie jest traktowane
// doslownie, nie jako wyrazenie do ewaluacji
console.log(tab.length)
console.log(tab['length'])

// Zmiana wartości właściwości length działa następująco:
// zmniejszenie tej wartości ogranicza liczbę elementów
// wyświetlanych przez console.log(tab), zwiększenie
// tej wartości dodaje puste miejsca w tablicy. Elementy
// o kluczach innych niz typu number nie wliczaja sie do
// tego ograniczenia i sa wyswietlane zawsze.
tab.length = 2
console.log(tab)

tab.length = 20
console.log(tab)












var color1 = new String("green"); //ciąg utworzony przy pomocy konstruktora
color1 instanceof String; // true
typeof color1; //object

var color2 = "coral"; //literał łańcuchowy
color2 instanceof String; // false
typeof color2; //string

console.log(color2 instanceof String)
console.log(color1 instanceof String)
console.log(typeof color1)
console.log(typeof color2)

// instanceof sprawdza czy dany obiekt był utworzony danym konstruktorem








let myObject = {
  myField: 'Hello',

  myMethod: function() {
    return this.myField;
  },

  get myProperty() {
    return this.myField.toUpperCase();
  },

  set myProperty(value) {
    this.myField = value;
  }
};
console.log(myObject) 
myObject.newField = 'World';
myObject.newMethod = function() {
  return 'New method!';
};
Object.defineProperty(myObject, 'newProperty', {
  get: function() {
    return this.newField.toUpperCase();
  },
  set: function(value) {
    this.newField = value;
  },
  enumerable: true
});
console.log(myObject)      












console.log((![]+[])[+[]]+(![]+[])[+!+[]]+([![]]+[][[]])[+!+[]+[+[]]]+(![]+[])[!+[]+!+[]]);

// Podzielmy wyrażenie na części:
(![]+[])[+[]] === (false + 0)[0] === 'false'[0] === 'f'
// ![] == false       negacja "prawdziwej" wartości
// ![]+[] == 'false'  dodanie [] powoduje, że oba argumenty '+' traktowane są jako napisy
// +[] == 0           unarny plus rzutuje swój argument na typ numeryczny
// Mamy zatem wyrażenie równoważne 'false'[0], czyli 'f'
(![]+[])[+!+[]] === 'false'[+ true] === 'false'[1] === 'a'
// (![]+[]) == 'false'   przeanalizowane wyżej
// +[] == 0              jak wyżej
// !+[] == true          negacja logiczna wartości numerycznej zero tworzy wartość boolowską 'true'
// +!+[] == 1            unarny plus rzutuje 'true' na liczbę 1
// Mamy zatem wyrażenie równoważne 'false'[1], czyli 'a'
([![]]+[][[]])[+!+[]+[+[]]] === ([false] + undefined)[1 + [0]] === 'falseundefined'['10'] === 'i'
// ![] == false                         przeanalizowane wyżej
// [![]] == [false]                     oczywiste
// [][[]] == undefined                  tablica [] nie ma elementu [[]]-tego, więc zwracane jest undefined
// [![]] + [][[]] == 'falseundefined'   plus zaaplikowany do tablicy rzutuje oba argumenty na napisy
// +[] == 0                             przeanalizowane wyżej
// [+[]] == [0]                         oczywiste
// +!+[] == 1                           przeanalizowane wyżej
// +!+[]+[+[]] == '10'                  dodawanie liczby 1 i tablicy [0] powoduje rzutowanie obu wartości na napisy '1' i '0'
// Mamy zatem wyrażenie równoważne 'falseundefined'['10'], czyli 'i' ('10' jest rzutowane na wartość numeryczną)
(![]+[])[!+[]+!+[]] === 'false'[true + true] === 'false'[2] === 'l'
// ![]+[] == 'false'    przeanalizowane wyżej
// !+[] == true         przeanalizowany wyżej
// !+[]+!+[] == 2       operator + rzutuje wartości boolowskie (true == 1) na wartości numeryczne
// Mamy zatem wyrażenie równoważne 'false'[2]

'false'[0] + 'false'[1] + 'falseundefined'['10'] + 'false'[2] == 'f' + 'a' + 'i' + 'l' == 'fail'




/*
    Operator "instanceof" działa jak predykat, pozwalający sprawdzić, czy
    dana wartość jest instancją pewnego typu (konstruktora). Zwraca wartość
    boolowską.
*/

console.log(new String("WEPPO") instanceof String)
console.log("WEPPO" instanceof String)

console.log(new Number(42) instanceof Number)

/*
    Operator "typeof" pozwala na uzyskanie typu danego wyrażenia. Zwraca napis
    reprezentujący ten typ. Zwracany typ to albo wyrażenie typu prostego, albo
    "object".
*/

console.log(typeof 42) // number
console.log(typeof(new Number(42)))

console.log(typeof "qwerty") // string
console.log(typeof(new String("qwerty"))) // object