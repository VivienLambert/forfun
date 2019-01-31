# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlambert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 10:47:24 by vlambert          #+#    #+#              #
#    Updated: 2018/12/05 10:41:51 by vlambert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
FLAGS= -Wall -Wextra -Werror
SRC= main.c table.c clean.c solve.c soltable.c
LIB= libft/libft.a
HEADER= -I libft
OBJ = main.o table.o clean.o solve.o soltable.o

all: $(NAME)

$(NAME): $(SRC)
	@ make -C libft/
	@ gcc $(FLAGS) -c $? $(HEADER)
	@ gcc -o $(NAME) $(OBJ) $(HEADER) $(LIB)
	@ echo "Fillit est cree"

clean:
	@ make -C libft/ clean
	@ rm -rf $(OBJ)
	@ echo "Les .o sont supprimes"

fclean: clean
	@ make -C libft/ fclean
	@ rm -rf $(NAME)
	@ echo "Fillit est supprime"

re: fclean all

.PHONY: clean fclean re
