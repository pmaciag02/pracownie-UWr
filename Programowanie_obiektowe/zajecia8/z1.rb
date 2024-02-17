class Fixnum
    def czynniki
        t = []
        
        1.upto(self) do |x|
            if self % x == 0
                t.push(x)
            end
        end

        return t
    end

    def ack(y)
        if self == 0
            return y + 1
        elsif y == 0
            return (self - 1).ack(1)
        else
            return (self - 1).ack(self.ack(y - 1))
        end
    end


    def doskonala
		suma = 0
		t = self.czynniki
        
        t.each {|x| 
        if x < self 
            suma += x 
        end}

		if suma == self
			return true
		else
			return false
		end
	end



    def slownie

        slownik = {0 => "zero", 1 => "jeden", 2 => "dwa", 3 => "trzy", 4 => "cztery", 5 => "piec", 6 => "szesc", 7 => "siedem", 8 => "osiem", 9 => "dziewiec"}

        wynik = String.new
        temp = self

        while temp > 0 do
            wynik = slownik[temp % 10] + " " + wynik
            temp /= 10
        end

        return wynik
    end
end


print 6.czynniki, "\n"

print 2.ack(1), "\n"

print 6.doskonala, "\n"
print 9.doskonala, "\n"

print 123.slownie, "\n"