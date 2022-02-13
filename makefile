CFLAGS = -Wall -Wextra -Werror

NAME = rush-02
SRC = ./
HEADERS =  ./includes/ft.h
all:
	gcc $(SRC)*.c -o $(NAME) 
push:
	git add *.c *.h Makefile
futureall: 
	gcc $(CFLAGS) $(SRC)*.c -o $(NAME) 
clean: 
	rm -f $(SRC)*.o
fclean: clean
	rm -f $(NAME)
re: fclean all