# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/15 20:20:19 by lmatshay          #+#    #+#              #
#    Updated: 2016/07/17 18:18:25 by lmatshay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

HEADERS = -I include

SRCS = \
	srcs/main.c\
	helper/ft_put_char.c\
	helper/ft_put_cyan.c\
	helper/ft_put_endl.c\
	srcs/highlight_word.c\
	helper/ft_put_magneta.c\
	helper/ft_put_str.c \
	srcs/underline_word.c\
	srcs/highlight_underline.c \
	srcs/term_behavior.c\
	srcs/save_and_display.c \
	srcs/take_over_terminal.c\
	srcs/signal_handling.c \
	srcs/reset_to_term.c\
	srcs/keyhook.c srcs/leave_select.c \
	srcs/adding_to_list.c\
	srcs/free_memory.c\
	srcs/print_list.c \
	helper/ft_strdup.c\
	srcs/go_up.c\
	srcs/go_down.c\
	helper/ft_select_item.c \
	srcs/enter_data.c\
	srcs/delete_item.c\
	srcs/changing_window.c \
	srcs/longest_item_in_term.c\
	helper/ft_put_char_fd.c\
	helper/ft_put_str_fd.c

LIB = -ltermcap

FLAGS = -Wall -Werror -Wextra

all: author
	@gcc $(FLAGS) $(SRCS) $(HEADERS) $(LIB)
	@mv a.out $(NAME)

clean:
	@rm $(NAME)

fclean: clean
	@rm author

re: clean all

switch: fclean all

author:
	@whoami > author
