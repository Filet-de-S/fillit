NAME = fillit

SRC = main.c \
	  extra.c \
	  algo.c \
	  algofunc.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C lib
	gcc -g -Wall -Wextra -Werror -I lib/includes -c $(SRC)
	gcc -g -o $(NAME) $(OBJ) -L lib -lft

clean:
	rm -f $(OBJ)
	make -C lib clean

fclean: clean
	rm -f $(NAME)
	make -C lib fclean

re: fclean all
