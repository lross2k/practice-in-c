.PHONY: exp clean

build : gasket.c
	gcc -std=c89 -Wall -Werror -Wshadow -Wextra -pedantic gasket.c -L. -I. -lAD

# export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH

clean : a.out
	rm a.out
