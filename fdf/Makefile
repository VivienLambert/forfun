# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlambert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 14:22:18 by vlambert          #+#    #+#              #
#    Updated: 2019/01/16 13:22:56 by vlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	fdf
FLAGS=	-Wall -Wextra -Werror
SRC=	main.c bresenham.c bresenham_right.c bresenham_left.c readmap.c\
		iso.c parallele.c setarg.c image.c keys.c
OBJ=	$(SRC:.c=.o)
LIB=	libft/libft.a -L minilibx_macos -lmlx
HEADER=	minilibx_macos/
FRAM=	-framework OpenGL -framework Appkit

all:		$(NAME)

$(NAME):	$(SRC)
	@ make --silent $(OBJ)
	@ make --silent -C libft/
	@ gcc $(FLAGS) -I $(HEADER) -o $(NAME) $(OBJ) $(LIB) $(FRAM)
	@ echo "$(NAME) est compilé"

$(OBJ):		$(SRC)
	gcc $(FLAGS) -I $(HEADER) -c $?

clean:
	@ make -C libft/ clean
	@ rm -rf $(OBJ)
	@ echo "Les .o sont supprimés"

fclean:		clean
	@ make -C libft/ fclean
	@ rm -rf $(NAME)
	@ echo "$(NAME) est supprimé"

re:			fclean all

.PHONY: clean fclean re
