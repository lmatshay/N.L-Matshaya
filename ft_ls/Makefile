# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmacheke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/11 10:06:01 by mmacheke          #+#    #+#              #
#    Updated: 2016/06/11 10:06:17 by mmacheke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	/usr/bin/clang
RM =	/bin/rm
MAKE =	/usr/bin/make
MKDIR =	/bin/mkdir

NAME = ft_ls

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/objs
CPATH =		$(ROOT)/srcs
HPATH =		$(ROOT)/includes
LIBPATH =	$(ROOT)/libft
LFTHPATH =	$(LIBPATH)/includes

CFLAGS = -Wall -Werror -Wextra -I $(HPATH) -I $(LFTHPATH)
LIBS = -L $(LIBPATH) -lft

SRC = 	ft_ls.c \
		ft_ls_getinfo.c \
		ft_ls_display.c \
		ft_ls_fileinfo.c \
		ft_ls_managedir.c \
		ft_ls_managelst.c \
		ft_ls_permissions.c \
		ft_ls_manageoptions.c \
		ft_ls_displayoptions.c

OFILES = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re norm

all: $(OPATH) $(NAME)

$(NAME): $(OFILES)
	@$(MAKE) -C $(LIBPATH)
	@echo "Creating/making obj files"
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "All is done!"

$(OPATH)/%.o: $(CPATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "Creating obj directory"
	@$(MKDIR) $@

clean:
	@echo "Deleting obj files"
	@$(RM) -rf $(OPATH)

lib.fclean:
	@$(MAKE) fclean -C $(LIBPATH)

fclean: clean lib.fclean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "All clear!"

re: fclean all


