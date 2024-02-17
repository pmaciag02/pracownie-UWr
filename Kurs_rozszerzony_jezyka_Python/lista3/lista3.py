import timeit



def tabelka(funkcja1, funkcja2, funkcja3):
    print("{: >0} {: >30} {: >30} {: >30}".format(*['n', "imperatywna", "skladana", "funkcyjna"]))
    for i in range(1, 10):
        print("{: >0} {: >30} {: >30} {: >30}".format(*[i * 10, timeit.timeit(funkcja1 + '(' + str(i * 10) + ')', setup= "from __main__ import " + funkcja1, number = 1), timeit.timeit(funkcja2 + '(' + str(i * 10) + ')', setup= "from __main__ import " + funkcja2, number = 1), timeit.timeit(funkcja3 + '(' + str(i * 10) + ')', setup= "from __main__ import " + funkcja3, number = 1)]))
    print('\n')



#z1

import math


def czy_pierwsze(n):
	for i in range(2, math.floor(math.sqrt(n)) + 1):
		if n % i == 0:
			return False
	return True



def pierwsze_imperatywna(n):
	t = []
	for i in range(2, n + 1):
		pierwsza = True

		for j in range(2, i):
			if i % j == 0:
				pierwsza = False

		if pierwsza:
			t.append(i)
	return t


def pierwsze_skladana(n):
	return [i for i in range(2, n + 1) if all(i % j != 0 for j in range(2, i))]

def pierwsze_skladana2(n):
	return [i for i in range(2, n + 1) if all(i % j != 0 for j in range(2, i))]



def pierwsze_funkcyjna(n):
	return list(filter(lambda x: czy_pierwsze(x), range(2, n+1)))


tabelka("pierwsze_imperatywna", "pierwsze_skladana", "pierwsze_funkcyjna")


#z2


def doskonala(n):
    s = 0
    for i in range(1, (n // 2) + 1):
        if n % i == 0:
            s += i
    return s == n


def doskonale_imperatywna(n):
	t = []
	for i in range(6, n + 1):
		s = 0
		for j in range(1, (i // 2) + 1):
			if i % j == 0:
				s += j
		if s == i:
			t.append(i)
	return t


def doskonale_skladana(n):
	return [i for i in range(6, n + 1) if sum(j for j in range(1, (i // 2) + 1) if i % j == 0) == i]


def doskonale_funkcyjna(n):
	return list(filter(lambda x : doskonala(x), range(6, n + 1)))



tabelka("doskonale_imperatywna", "doskonale_skladana", "doskonale_funkcyjna")
