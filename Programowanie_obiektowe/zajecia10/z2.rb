class Kolekcja

    def initialize
        @lista = Array.new
        @dlugosc = 0
    end

    def dlugosc
        return @dlugosc
    end

    def get(i)
        raise ArgumentError, "Pozycja na liście musi być liczbą całkowitą dodatnią" if i <= 0 || i.class != Integer
        return "Na liście nie ma pozycji nr #{i}" if i > @dlugosc
        return @lista[i]
    end

    def dodaj(x)
        @dlugosc += 1
        poz = self.pozycja(1, @dlugosc, x)
        i = @dlugosc
        while (i > poz)
            @lista[i] = @lista[i - 1]
            i -= 1
        end 
        @lista[poz] = x;
    end

    def pozycja(lewy, prawy, szukana)
        return lewy if (lewy >= prawy)
        srodkowy = (lewy + prawy)/2
        if (szukana < @lista[srodkowy])
            return self.pozycja(lewy, srodkowy, szukana)
        else
            return self.pozycja(srodkowy + 1, prawy, szukana)
        end
    end

    def odczyt_listy
        if (@dlugosc == 0)
            print "Lista jest pusta\n"
        else
            print "["
            for i in 1...@dlugosc do
                print @lista[i], ", "
            end
            print @lista[@dlugosc], "]\n"
        end
    end
end

class Wyszukiwanie

    def binarne(szukana, lista)
        lewy = 1
        prawy = lista.dlugosc
        while (lewy <= prawy)
            srodkowy = (lewy + prawy)/2
            return srodkowy if (lista.get(srodkowy) == szukana)
            if (szukana < lista.get(srodkowy))
                prawy = srodkowy - 1
            else
                lewy = srodkowy + 1
            end
        end
        return "Element #{szukana} nie występuje na liście"
    end

    def interpolacyjne(szukana, lista)
        lewy = 1
        prawy = lista.dlugosc
        while (lewy <= prawy)
            srodkowy = lewy + (szukana - lista.get(lewy.floor)) * (prawy - lewy) / (lista.get(prawy.floor) - lista.get(lewy.floor))
            return srodkowy.floor if (lista.get(srodkowy.floor) == szukana)
            if (szukana < lista.get(srodkowy.floor))
                prawy = srodkowy - 1
            else
                lewy = srodkowy + 1
            end
        end
        return "Element #{szukana} nie występuje na liście"
    end
end

lista = Kolekcja.new
lista.dodaj(42)
lista.odczyt_listy
lista.dodaj(21)
lista.odczyt_listy
lista.dodaj(37)
lista.odczyt_listy
lista.dodaj(-100)
lista.odczyt_listy
lista.dodaj(121000)
lista.odczyt_listy
lista.dodaj(5.0)
lista.odczyt_listy
lista.dodaj(32.3)
lista.odczyt_listy
lista.dodaj(-42.42)
lista.odczyt_listy
lista.dodaj(123)
lista.odczyt_listy
lista.dodaj(456)
lista.odczyt_listy
print "Element na pozycji nr 3: ", lista.get(3), "\n"
print "Element na pozycji nr 9: ", lista.get(9), "\n"
print "Element na pozycji nr 14: ", lista.get(14), "\n"
print "Długość listy: ", lista.dlugosc, "\n"

szukaj = Wyszukiwanie.new
print "Element 42 znajduje się na pozycji: ", szukaj.binarne(42, lista), "\n"
print "Element -100 znajduje się na pozycji: ", szukaj.binarne(-100, lista), "\n"
print "Element 121000 znajduje się na pozycji: ", szukaj.binarne(121000, lista), "\n"
print "Element 0 znajduje się na pozycji: ", szukaj.binarne(0, lista), "\n"
print "Element 42 znajduje się na pozycji: ", szukaj.interpolacyjne(42, lista), "\n"
print "Element -100 znajduje się na pozycji: ", szukaj.interpolacyjne(-100, lista), "\n"
print "Element 121000 znajduje się na pozycji: ", szukaj.interpolacyjne(121000, lista), "\n"
print "Element 0 znajduje się na pozycji: ", szukaj.interpolacyjne(0, lista), "\n"