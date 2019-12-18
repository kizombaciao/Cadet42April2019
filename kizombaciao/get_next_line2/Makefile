NAME = get_next_line2

SRC_PATH = ./
SRCS =	main.c
SRCS +=	get_next_line.c
SRCS +=	./libft/ft_putchar.c
SRCS +=	./libft/ft_putstr.c
SRCS +=	./libft/ft_strlen.c
SRCS +=	./libft/ft_strdup.c
SRCS +=	./libft/ft_memcpy.c
SRCS +=	./libft/ft_strjoin.c
SRCS +=	./libft/ft_strchr.c
SRCS +=	./libft/ft_strsub.c
SRCS +=	./libft/ft_memdel.c
SRCS +=	./libft/ft_strdel.c
#SRCS +=	./libft/ft_strnew.c ### DDD
#SRCS +=	./libft/ft_memalloc.c ### DDD
#SRCS +=	./libft/ft_bzero.c ### DDD

SRC = $(addprefix $(SRC_PATH), $(SRCS)) 

HEAD = ./get_next_line.h
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEL = rm -f

all: $(NAME)

$(NAME):
	#@gcc $(FLAG) -c $(SRC) -I $(HEAD)
	#@ar rc $(NAME) $(OBJ)
	#@ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"
	#gcc main.c -L. -lft
	#gcc $(FLAG) -o $(NAME) $(OBJ) -I $(HEAD)	
	gcc -o $(NAME) $(SRC) -I $(HEAD)

clean:
	@$(DEL) $(OBJ)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean:	clean
	@$(DEL) $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

re: fclean all

debug:
	gcc -g -o $(NAME) $(SRC) -I $(HEAD)
