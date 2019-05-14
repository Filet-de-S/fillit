NAME = fillit

SRC = main.c \ 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C lib/
	gcc -o $(NAME) $(SRC) -I lib/includes -L lib/ -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
