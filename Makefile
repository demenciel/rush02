CFLAGS = -Wall -Werror -Wextra -O2

rush-02: main.o
	gcc $(CFLAGS) main.o -o rush-02

main.o: main.c
	gcc $(CFLAGS) -c main.c

fclean:
	rm -f *.o rush-02
