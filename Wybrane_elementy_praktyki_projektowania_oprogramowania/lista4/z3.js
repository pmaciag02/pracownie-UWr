var Person = function(name, surname) {
    this.name = name;
    this.surname = surname;
}

Person.prototype.say = function() {
    return `${this.name} ${this.surname}`;
}

var p = new Person('jan', 'kowalski');
console.log( p.say() );


var Worker = function(name, surname, age) {
    // wywołanie bazowej funkcji konstruktorowej
    Person.call( this, name, surname );
    this.age = age;
}
// powiązanie łańcucha prototypów
Worker.prototype = Object.create( Person.prototype );

Worker.prototype.say = function() {
    // "wywołanie metody z klasy bazowej"
    var _ = Person.prototype.say.call( this );
    return `${_} ${this.age}`;
}
var w = new Worker('jan', 'kowalski', 48);
console.log( w.say() );





// Worker.prototype = Person.prototype: W tym przypadku, obie klasy (Worker i Person) dzieliłyby ten sam prototyp. To oznacza, że każda zmiana w prototypie jednej klasy miałaoby wpływ na drugą klasę. To może prowadzić do nieoczekiwanych i trudnych do zlokalizowania błędów.

// Worker.prototype = new Person(): Tworzenie nowej instancji Person w celu ustawienia prototypu Worker jest problematyczne, ponieważ ta nowa instancja Person może zawierać własne dane, które nie mają nic wspólnego z klasą Worker. Ponadto, jeśli konstruktor Person wymaga argumentów, konstruktor Worker też musiałby je dostarczyć, co może prowadzić do niepożądanych efektów ubocznych.

// W związku z tym, najlepszym podejściem w tym przypadku jest użycie Object.create(Person.prototype), co pozwala na ustanowienie łańcucha prototypów, zachowując niezależność między klasami.