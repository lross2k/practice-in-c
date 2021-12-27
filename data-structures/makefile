.PHONY :
	build

build : static clean_o

static : objects
	ar -crs libAllDS.a *o

objects :
	gcc -c linked-list/int-list.c queue/queue-by-list.c -I.

clean :
	rm liballds.a

clean_o :
	rm *.o
