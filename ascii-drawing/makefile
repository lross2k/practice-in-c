shared : ascii-drawing.o
	gcc -shared -fPIC -O3 -Wall -Werror -Wextra -Wshadow -pedantic -std=c89 -o libAD.so ascii-drawing.o

static : ascii-drawing.o
	ar -crs libAD.a ascii-drawing.o

ascii-drawing.o : ascii-drawing.c
	gcc -c -fPIC -no-pie -O3 -Wall -Werror -Wextra -Wshadow -pedantic -std=c89 ascii-drawing.c -I. 

clean :
	rm libAD.so libAD.a ascii-drawing.o
