all:fastPow

fastPow: fastPower.c
	gcc fastPower.c -o fastPow

clean:
	rm -f fastPow
