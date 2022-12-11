CFLAGS = -Wall -Werror -Wextra -O2

rush-02: main.o print_functions.o 
	gcc $(CFLAGS) main.o print_functions.o -o rush-02

main.o: main.c
	gcc $(CFLAGS) -c main.c

print_functions.o: print_functions.c
	gcc $(CFLAGS) -c print_functions.c

fclean:
	rm -f *.o rush-02
