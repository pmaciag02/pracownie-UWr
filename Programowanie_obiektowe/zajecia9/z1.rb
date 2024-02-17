class Function
	def initialize(procedure)
		@proc = procedure
	end


	def value(x)
		@proc.call(x)
	end




	def zero(a, b, e)
		t = []

		while a <= b
			if value(a) == 0
				t.push(a)
			end

			a+=e
		end

		if t == []
			nil
		else
			t
		end
		
	end



	def field(a,b)
		@@h = 0.001
		
		if a>=b
			0
		else
			((value(a) + value(a + @@h) ) * @@h / 2.0) + field(a+ @@h, b)
		end
	end




	def deriv(x)
		@@h = 0.0001
		(value(x + @@h) - value(x) ) / @@h 

	end
end


f = Function.new(Proc.new{|x| x**3 + x**2})

print f.zero(-5,2,001), "\n"