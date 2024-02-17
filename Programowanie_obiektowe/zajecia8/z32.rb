class Jawna
    def initialize(message)
        @code = message         # Variable with the same type as 'message'.
    end

    def zaszyfruj(key)
        @res = String.new       # Variable with deciphered code.
        @code.each_char do |c|  # For each sign decipher code.
            @res += key[c]
        end
        @code = @res            # Save result to the variable in class.
    end

    def to_s
        @code                   # Return ciphered message (no need to write 'return ...')
    end
end

class Zaszyfrowana
    def initialize(message)
        @ciphered = message
    end

    def decipher(key)
        @res = String.new
        key = key.invert        # Swap keys in dict ("a" => "d" becomes "d" => "a" etc.)
        
        @ciphered.each_char do |c|
            @res += key[c]
        end
        
        @ciphered = @res
    end

    def to_s
        @ciphered
    end
end

Klucz = Hash[" " => " ", "a" => "b", "b" => "c", "c" => "d", "d" => "e",
"e" => "f", "f" => "g", "g" => "h", "h" => "i", "i" => "j",
"j" => "k", "k" => "l", "l" => "m", "m" => "n", "n" => "o",
"o" => "p", "p" => "r", "r" => "s", "s" => "t", "t" => "u",
"u" => "v", "v" => "w", "w" => "x", "x" => "y", "y" => "z", "z" => "a"]

# Object we want to cipher.
toCipher = Jawna.new("abcdefghijklmnoprstuvwxyz")
toCipher.zaszyfruj(Klucz)
puts toCipher.to_s    # prints ciphered code.

# Object we want to decipher.
toDecipher = Zaszyfrowana.new(toCipher.to_s)
toDecipher.decipher(Klucz)
puts toDecipher.to_s

anotherToCipher = Jawna.new("there is some text that will become ciphered soon")
anotherToCipher.zaszyfruj(Klucz)
puts anotherToCipher.to_s

anotherToDecipher = Zaszyfrowana.new(anotherToCipher.to_s)
anotherToDecipher.decipher(Klucz)
puts anotherToDecipher.to_s