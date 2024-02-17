function Foo() {
    // Funkcja prywatna Qux jest zdefiniowana wewnątrz domknięcia funkcji Foo
    function Qux() {
      console.log("To jest funkcja prywatna Qux");
    }
  
    // Metoda publiczna Bar, która może być wywoływana na instancjach obiektów Foo
    this.Bar = function() {
      console.log("To jest metoda publiczna Bar");
  
      // Wywołanie funkcji prywatnej Qux wewnątrz metody Bar
      Qux();
    };
  }
  
  // Przykład użycia:
  
  let myFoo = new Foo();
  myFoo.Bar(); // Wywołuje metodę publiczną Bar, która wywołuje funkcję prywatną Qux
  
  // Poniższe dwie linie spowodują błędy, ponieważ funkcja Qux nie jest dostępna na zewnątrz funkcji Foo
  // myFoo.Qux(); // Błąd - Qux nie jest funkcją publiczną
  // Qux(); // Błąd - Qux nie jest zdefiniowane globalnie
  