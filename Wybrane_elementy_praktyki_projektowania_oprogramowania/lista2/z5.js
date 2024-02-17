let uczen = {
  klasa: 1,

  Poziom: function() {
    return this.klasa;
  },

  get klasaUcznia() {
    return this.klasa;
  },

  set klasaUcznia(n) {
    this.klasa = n;
  }
};

console.log(uczen)




uczen.imie = 'Jan'

uczen.podajImie = function() {
  return this.imie
}



Object.defineProperty(uczen, 'imieUcznia', {
  get: function() {
    return this.imie;
  },
  set: function(s) {
    this.imie = s;
  },
  enumerable: true
});


console.log(uczen)