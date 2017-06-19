CC=gcc
CFLAGS=-O2 -Wall -Wextra -Werror
DEPS = sort.h
OBJ = sort.o selection_sort.o insertion_sort.o merge_sort.o quicksort.o heapsort.o radix_lsd_sort.o

%.o:	%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

sort:	main.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
