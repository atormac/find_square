
NAME = find_square

SOURCES =  str.c \
		  map.c \
		  print.c \
		  matrix.c \
		  line.c \
		  square.c \
		  file.c \
		  main.c \
		  find.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Werror -Wextra -O3

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
