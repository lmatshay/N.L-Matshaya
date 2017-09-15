# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/26 10:39:27 by lmatshay          #+#    #+#              #
#    Updated: 2016/09/11 12:24:34 by lmatshay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = "minishell" 

SOURCES = \
		  helper/str_clr.c \
		  helper/str_cpy.c \
		  helper/str_del.c \
		  helper/str_new.c \
		  helper/str_len.c \
		  helper/str_dup.c \
		  helper/put_chr.c \
		  helper/put_str.c \
		  helper/put_endl.c \
		  helper/str_join.c \
		  helper/str_split.c \
		  helper/get_char.c \
		  helper/read_line.c \
		  helper/resize_str.c \
		  helper/del_strs.c \
		  helper/str_cmp.c \
		  src/get_path.c \
		  src/found_in_path.c \
		  src/execute_command.c \
		  src/launch_process.c \
		  src/func_cd.c \
		  src/func_help.c \
		  helper/mem_for_str_split.c \
		  src/unset_env.c \
		  src/set_env.c \
		  helper/ft_atoi.c \
		  src/get_name.c \
		  src/get_value.c \
		  src/func_env.c \
		  src/print_environ.c \
		  src/func_export.c \
		  src/func_unset.c \
		  helper/str_chr.c \
		  src/func_echo.c \
		  src/minishell.c \
		  helper/put_nbr.c\
		  src/args.c \
		  helper/ft_dstrlen.c\
		  helper/ft_index.c \
		  src/shellname.c \
		  src/gen_pipes.c \
		  helper/ft_pipe.c \
		  helper/ft_free2d.c \
		  helper/freed.c \
		  helper/add_color.c \
		  src/create_node.c\



HEADER = minishell.h

FLAGS = -Wall -Werror -Wextra

all:
	@gcc $(FLAGS) $(SOURCES) $(HEADER)
	@mv a.out $(NAME)
	@rm minishell.h.gch
	@echo "\033[32mminishell built successfully.\033[0m"

clean:
	@rm $(NAME)
	@echo "\033[32mcleaned successfully.\033[0m"

re: clean all

norm:
	@echo "\033[32mrunning norminette on directory -helper-\033[0m"
	@norminette helper/
	@echo "\033[32m----->>>completed 1 / 3<<<-----\033[0m"
	@echo "\033[32mrunning norminette on directory -src-\033[0m"
	@norminette src/
	@echo "\033[32m----->>>completed 2 / 3<<<-----\033[0m"
	@echo "\033[32mrunning norminette on header file-\033[0m"
	@norminette $(HEADER)
	@echo "\033[32m----->>>completed 3 / 3<<<-----\033[0m"

