NAME = libft.a

SRC = get_next_line.c \
	  ft_memset.c \
	  ft_putendl.c \
	  ft_lstdelone.c \
	  ft_lstnew.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstaddend.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_putendl_fd.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_bzero.c \
	  ft_putstr.c \
	  ft_memdl.c \
	  ft_putchar.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_strtrim.c \
	  ft_strjoin.c \
	  ft_strsub.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_memmove.c \
	  ft_strlen.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_atoi.c \
	  ft_isalpha.c \
	  ft_isdigit.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strlcat.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strclr.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -g -I includes/ -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
