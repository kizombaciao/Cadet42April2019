# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cchao <cchao@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 16:30:11 by cchao             #+#    #+#              #
#    Updated: 2019/05/18 23:14:43 by cchao            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = ./
SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memdup.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnlen.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c
SRCS +=	ft_lstadd.c
SRCS +=	ft_lstcreate.c
SRCS +=	ft_lstdel.c
SRCS +=	ft_lstdelone.c
SRCS +=	ft_lstiter.c
SRCS +=	ft_lstlen.c
SRCS +=	ft_lstmap.c
SRCS +=	ft_lstnew.c
SRCS +=	ft_is_prime.c
SRCS +=	ft_sort_integer_table.c
SRCS +=	ft_str_is_alpha.c
SRCS +=	ft_str_is_lowercase.c
SRCS +=	ft_str_is_numeric.c
SRCS +=	ft_str_is_uppercase.c
SRCS +=	ft_strlowcase.c
SRCS +=	ft_strupcase.c
#SRCS +=	main.c

SRC = $(addprefix $(SRC_PATH), $(SRCS)) 

HEAD = ./libft.h
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror
DEL = rm -f

all: $(NAME)

$(NAME):
	@gcc $(FLAG) -c $(SRC) -I $(HEAD)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "[=================]"
	@echo "|     succes !    |"
	@echo "|     libft.a     |"
	@echo "|   was summoned  |"
	@echo "[=================]"
	#gcc main.c -L. -lft
	#gcc $(FLAG) -o $(NAME) $(OBJ) -I $(HEAD)	
	#gcc -o $(NAME) $(SRC) -I $(HEAD)

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
		