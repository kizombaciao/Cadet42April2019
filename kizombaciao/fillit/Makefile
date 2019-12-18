NAME = fillit

SRC_PATH = ./
SRCS =	./fillit_project/main.c
SRCS +=	./fillit_project/toread.c
SRCS +=	./fillit_project/tovalidate.c
SRCS +=	./fillit_project/tosolve.c
SRCS +=	./fillit_project/toprint.c
SRCS +=	./fillit_project/toalign.c
SRCS +=	./fillit_project/tomap.c
SRCS +=	./libft/ft_putstr.c
SRCS +=	./libft/ft_putchar.c
SRCS +=	./libft/ft_memalloc.c
SRCS +=	./libft/ft_bzero.c
SRCS +=	./libft/ft_strnew.c
SRCS +=	./libft/ft_memset.c
SRCS +=	./libft/ft_memdel.c


SRC = $(addprefix $(SRC_PATH), $(SRCS)) 

LIBFT = libft/
HEAD = ./fillit_project/fillit.h
OBJ = *.o
FLAG = -Wall -Wextra -Werror
DEL = rm -f

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc $(FLAG) -o $(NAME) $(SRC) -I $(HEAD) -L. libft/libft.a
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"

clean:
	@$(DEL) $(OBJ)
	@make -C $(LIBFT) clean
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     XXXXX.o     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

fclean:	clean
	@$(DEL) $(NAME)
	@make -C $(LIBFT) fclean
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|  was destroyed  |"
	@echo "[=================]"

re: fclean all

debug:
	gcc -g -o $(NAME) $(SRC) -I $(HEAD)
