NAME = fillit

SRC = main.c \
	  extra.c \
	  algo.c \
	  algofunc.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C lib
	gcc -g -Wall -Wextra -Werror $(SRC) -I lib/includes -L lib/ -lft -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
