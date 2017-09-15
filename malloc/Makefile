# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/18 13:11:16 by lmatshay          #+#    #+#              #
#    Updated: 2017/06/18 17:30:03 by lmatshay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME =			libft_malloc_$(HOSTTYPE).so

CC =			gcc $(FLAGS) $(INCLUDES)

LINK =			libft_malloc.so

LIBFT =			-L./libft -lft

LIB =			./libft/libft.a

INCLUDES =		-I./includes -I./libft/includes

SRC =			malloc.c show_alloc_mem.c list.c free.c create.c

OBJ =			$(SRC:.c=.o)

FLAGS =			-Wall -Wextra -Werror

all:			$(LIB) $(NAME)
$(LIB):
				Make -C libft
$(NAME):		$(OBJ)

clean:
				Make -C libft clean
				rm -f $(OBJ)
fclean:
				Make -C libft fclean
				rm -f $(OBJ)
				rm -f $(NAME)
				rm -f $(LINK)

re:				fclean all
				all clean re fclean

%.o:			%.c
				$(CC) -c $< -o $@
