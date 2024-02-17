// Użycie operatorów . oraz [] do odwoływania się do składowych obiektu.

let uczen = {
    klasa: 1,
    "imie i nazwisko": 'Jan Kowalski',
    wypiszDane: function() {
        console.log(this["imie i nazwisko"], this.klasa)
    }
}

console.log(uczen.klasa)
// console.log(uczen[klasa])
console.log(uczen['klasa'])
uczen.wypiszDane()
console.log(uczen["imie i nazwisko"])
// console.log(uczen[wypiszDane])
// console.log(uczen."imie i nazwisko")







// Użycie argumentów innego typu niż string dla operatora [] dostępu do składowej obiektu.


// Co się dzieje jeśli argumentem operatora jest liczba?
// Liczba zostaje zamieniona na napis.
let liczby = {
    0: 'zero',
    1: 'jeden'
}

console.log(liczby[0])
console.log(liczby['0'])

// Co się dzieje jeśli argumentem operatora jest inny obiekt?

let a = {
    toString: function() {
        return 'klasa'
    }
}

console.log(uczen[a])

let b = {
    B: 'bbb'
}

let c = {}
c[b] = 10
console.log(c)

c[uczen] = 20
console.log(c)

// Jaki wpływ na klucz pod jakim zapisana zostanie wartość ma programista w obu przypadkach?
// W przypadku obiektów klucz zależy od metody toString, którą programista może zdefiniować.
// W przypadku liczb programista jest zdany na wbudowaną konwersję wartości numerycznych na napisy.






// Użycie argumentów innego typu niż number dla operatora [] dostępu do tablicy


// Co się dzieje jeśli argumentem operatora jest napis?

let array = [10, 20, 30]

console.log(array["0"])


array["word"] = "ABC"
console.log(array)
console.log(array.length)

// Co się dzieje jeśli argumentem operatora jest inny obiekt?

array[b] = {}
console.log(array)



// Czy i jak zmienia się zawartość tablicy jeśli zostanie do niej dopisana właściwość pod kluczem, który nie jest liczbą?
// Do tablicy dodawane są nowe atrybuty.

// Czy można ustawiać wartość atrybutu length tablicy na inną wartość niż liczba
// elementów w tej tablicy? Co się dzieje jeśli ustawia się wartość mniejszą niż liczba
// elementów, a co jeśli ustawia się wartość większą niż liczba elementów?

array.length = 1
console.log(array)

array.length = 10
console.log(array)