NAME = aaa

SRC_PATH = ./src/
SRCS =	main.c
SRCS +=	ft_printf.c
SRCS +=	other.c
SRC = $(addprefix $(SRC_PATH), $(SRCS)) 

INC = ./inc/ft_printf.h

LIBFT_PATH = ./libft/
LIBFT_SRCS = ft_bzero.c
LIBFT_SRC = $(addprefix $(LIBFT_PATH), $(LIBFT_SRCS)) 

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEL = rm -f

all: $(NAME)

$(NAME):
	#@gcc $(FLAG) -c $(SRC) -I $(INC)
	#@ar rc $(NAME) $(OBJ)
	#@ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"
	#gcc main.c -L. -lft
	#gcc $(FLAG) -o $(NAME) $(OBJ) -I $(INC)	
	gcc -o $(NAME) $(SRC) $(LIBFT_SRC) -I $(INC)

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