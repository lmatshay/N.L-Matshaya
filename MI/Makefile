# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/18 15:59:32 by lmatshay          #+#    #+#              #
#    Updated: 2016/07/04 18:06:31 by lmatshay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = helpers.c mem.c little.c  run_shell.c mini.c 

OBJ  = helpers.o little.o mem.o run_shell.o mini.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
