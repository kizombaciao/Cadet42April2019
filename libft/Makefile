NAME = aaa

SRC = ./main.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_putchar.c \
		ft_strcat.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strlen.c
		

HEAD = ./ft.h
OBJ = ./*.o
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	#gcc $(FLAG) -c $(SRC) -I $(HEAD)
	#gcc $(FLAG) -o $(NAME) $(OBJ) -I $(HEAD)
	#ar rc $(NAME) $(OBJ)
	#ranlib $(NAME)
	gcc -o $(NAME) $(SRC) -I $(HEAD)

clean:
	rm -f *.o

fclean:
	rm -f $(NAME) *.o
	
re: fclean all