gen : main.o
	gcc -std=c89 -Wall -Werror -O3 -pedantic -o gen main.o

main.o : main.c
	gcc -c -std=c89 -Wall -Werror -O3 -pedantic main.c

clean:
	rm gen main.o

