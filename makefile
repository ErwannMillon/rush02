CC		= gcc
CFLAGS	= -Werror -Wextra -Wall
DEPS	= test.c verify.c
OBJ		= test.o verify.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rush-02: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

fclean: $(OBJ) rush-02
	rm -f $^