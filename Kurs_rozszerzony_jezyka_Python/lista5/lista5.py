#z1A


import sys

class VariableNotFoundException(Exception):
    def __init__(self, *args: object):
        super().__init__(*args)
        #print("Błąd zmiennej!")
        #quit()


class Wyrazenie:
    def __init__(self, wyrazenie):
        self.wyrazenie = wyrazenie

    def __str__(self):
        return str(self.wyrazenie)
    
    #def oblicz(self, zmienne):
     #   return self.oblicz(zmienne)



class Stala(Wyrazenie):
    def __init__(self, stala):
        self.stala = stala

    def __str__(self):
        return str(self.stala)

    def oblicz(self, zmienne):
        return self.stala

    def __add__(self, arg):
        return Dodaj(self.stala, arg.stala)

    def __mul__(self, arg):
        return Razy(self.stala, arg.stala)


class Zmienna(Wyrazenie):
    def __init__(self, nazwa):
        self.nazwa = nazwa

    def __str__(self):
        return self.nazwa

    def oblicz(self, zmienne):
        for x in zmienne:
            if x[0] == self.nazwa:
                return x[1]
        raise VariableNotFoundException(print("Błąd zmiennej!"), quit())

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)



class Dodaj(Wyrazenie):
    def __init__(self, skladnik1, skladnik2):
        self.skladnik1 = skladnik1
        self.skladnik2 = skladnik2

    def __str__(self):
        return "(" + str(self.skladnik1) + " + " + str(self.skladnik2) + ")"

    def oblicz(self, zmienne):
        return self.skladnik1.oblicz(zmienne) + self.skladnik2.oblicz(zmienne)

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)

class Odejmij(Wyrazenie):
    def __init__(self, odjemna, odjemnik):
        self.odjemna = odjemna
        self.odjemnik = odjemnik

    def __str__(self):
        return "(" + str(self.odjemna) + " - " + str(self.odjemnik) + ")"

    def oblicz(self, zmienne):
        return self.odjemna.oblicz(zmienne) - self.odjemnik.oblicz(zmienne)

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)
    

class Razy(Wyrazenie):
    def __init__(self, czynnik1, czynnik2):
        self.czynnik1 = czynnik1
        self.czynnik2 = czynnik2

    def __str__(self):
        return "(" + str(self.czynnik1) + " * " + str(self.czynnik2) + ")"

    def oblicz(self, zmienne):
        return self.czynnik1.oblicz(zmienne) * self.czynnik2.oblicz(zmienne)

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)
    

class Podziel(Wyrazenie):
    def __init__(self, dzielna, dzielnik):
        self.dzielna = dzielna
        self.dzielnik = dzielnik

    def __str__(self):
        return "(" + str(self.dzielna) + " / " + str(self.dzielnik) + ")"

    def oblicz(self, zmienne):
        return self.dzielna.oblicz(zmienne) / self.dzielnik.oblicz(zmienne)

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)


w = Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("y"))
print(w)

print(w.oblicz([("x", 1), ("y", 2)]))








class Przypisz(Wyrazenie):
    def __init__(self, zmienna, wartosc):
        self.zmienna = zmienna
        self.wartosc = wartosc

    def __str__(self):
        return "(" + str(self.zmienna) + " = " + str(self.wartosc) + ")"

    def oblicz(self, zmienne):
        for x in zmienne:
            if x[0] == self.zmienna:
                t = self.wartosc.oblicz(zmienne)
                zmienne.append((x[0], t))
                zmienne.remove(x)
                return t
        zmienne.append((self.zmienna, self.wartosc.oblicz(zmienne)))
        

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)



class If(Wyrazenie):
    def __init__(self, warunek, instrukcje):
        self.warunek = warunek
        self.instrukcje = instrukcje

    def __str__(self):
        return "(If (" + str(self.warunek) + "){ " + str(self.instrukcje) + " })"

    def oblicz(self, zmienne):
        if self.warunek.oblicz(zmienne) != 0:
            return self.instrukcje.oblicz(zmienne)

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)


class While(Wyrazenie):
    def __init__(self, warunek, instrukcje):
        self.warunek = warunek
        self.instrukcje = instrukcje

    def __str__(self):
        return "(While (" + str(self.warunek) + "){ " + str(self.instrukcje) + " })"

    def oblicz(self, zmienne):
        while self.warunek.oblicz(zmienne) != 0:
            self.instrukcje.oblicz(zmienne)


    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)


w2 = Przypisz("x", Stala(1))
print(w2)

print(w2.oblicz([("x", 1), ("y", 2)]))




w3 = If(Dodaj(Zmienna("x"), Zmienna("y")), Stala(11))

print(w3)

print(w3.oblicz([("x", 1), ("y", 2)]))

w4 = Podziel(Stala(4), Stala(2))

print(w4)

print(w4.oblicz([("x", 1), ("y", 2)]))



class Wykonaj(Wyrazenie):
    def __init__(self, instrukcje):
        self.instrukcje = instrukcje

    def __str__(self):
        s = "Wykonaj("
        for x in self.instrukcje:
            s += str(x) + ", "
        if len(s) > 0:
            return s[:-2] + ")"
        else:
            return s + ")"

    def oblicz(self, zmienne):
        for x in self.instrukcje:
            print(x.oblicz(zmienne))

    def __add__(self, arg):
        return Dodaj(self, arg)

    def __mul__(self, arg):
        return Razy(self, arg)

w5 = Wykonaj([Razy(Dodaj(Zmienna("x"), Stala(2)), Zmienna("y")), Podziel(Stala(4), Stala(2))])

print(w5)

print(w5.oblicz([("x", 1), ("y", 2)]))

w6 = Wykonaj([While(Zmienna("x"), Przypisz("x", Odejmij(Zmienna("x"), Stala(1)))), Zmienna("x")])

print(w6)

print(w6.oblicz([("x", 1), ("y", 2)]))