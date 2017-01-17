
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wasman <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 09:26:58 by wasman            #+#    #+#              #
#    Updated: 2016/09/21 13:37:49 by wasman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = fillit

SOURCES =	classify_one.c classify_two.c classify_three.c classify_four.c\
			conflicts.c	contact.c\
			first_empty.c\
			fix_offset.c\
			generate_shifts.c\
			get_width.c\
			is_empty.c\
			is_valid_functions.c\
			is_valid_helpers.c\
			itoa_base.c\
			main.c\
			print.c\
			read.c\
			shift.c\
			shift_helpers.c\
			solve_functions.c\
			solved.c

OBJ = $(SOURCES:.c=.o)

LIBS = libft/libft.a

.PHONY: all norm clean fclean re

$(NAME): $(OBJ) $(LIBS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)


%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBS):
	make -C ./libft

all: $(NAME)

norm: fclean
	norminette $(SOURCES)

clean:
	make -C ./libft/ clean
	/bin/rm -f rm $(OBJ)

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f rm $(NAME)

re: fclean all
