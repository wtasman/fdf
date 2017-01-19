
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:26:58 by wasman            #+#    #+#              #
#    Updated: 2016/09/21 13:37:49 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
LDIR = ./libft
LIBDIR = $(LDIR)/libft.a
MLXDIR = ./minilibx/
MLX = $(MLXDIR)/mlx.a
IDIR = .
LFTLIB = -L$ $(LDIR) -lft
FINDLIB = -I $(MLXDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework Appkit
OBJ = $(SRC:.c=.o)

SRC = 	main.c\

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(FLAGS) $(FINDLIB) $(SRC) -o $(NAME)

$(OBJ): $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

$(SRC): $(LIBS) $(MLX)

$(MLX):
	make -C ./minilibx

$(LIB):
	make -C ./libft

norm: fclean
	norminette $(SOURCES)

clean:
	make -C ./minilibx/ clean
	make -C ./libft/ clean
	/bin/rm -f rm $(OBJ)

fclean: clean
	make -C ./minilibx/ fclean
	make -C ./libft/ fclean
	/bin/rm -f rm $(NAME)

re: fclean all

.PHONY: all norm clean fclean re