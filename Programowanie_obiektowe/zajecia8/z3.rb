class Jawna
    def initialize(s)
        @napis = s
    end

    def zaszyfruj(key)
        @temp = String.new
        
        @napis.each_char do |i|
            @temp += key[i]
        end
        Zaszyfrowana.new(@temp)
    end

    def to_s
        @napis
    end
end

class Zaszyfrowana
    def initialize(s)
        @szyfr = s
    end

    def odszyfruj(key)
        @temp = String.new
        
        @szyfr.each_char do |i|
            @temp += key[i]
        end
        Jawna.new(@temp)
    end

    def to_s
        @szyfr
    end
end


Slownik = {'a' => 'b', 'b' => 'r', 'r' => 'y', 'y' => 'u', 'u' => 'a'}

zdanie = Jawna.new("ruby")
zdanie = zdanie.zaszyfruj(Slownik)
print zdanie.to_s, "\n"

zdanie = zdanie.odszyfruj(Slownik)
print zdanie.to_s, "\n"