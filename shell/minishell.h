/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:56:02 by lmatshay          #+#    #+#             */
/*   Updated: 2016/11/17 12:34:46 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>

/*
** Colours *********************************************************************
*/

# define ANSI_COLOR_RED     "\x1b[31m"
# define ANSI_COLOR_GREEN   "\x1b[32m"
# define ANSI_COLOR_YELLOW  "\x1b[33m"
# define ANSI_COLOR_BLUE    "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# define ANSI_COLOR_CYAN    "\x1b[36m"
# define ANSI_COLOR_RESET   "\x1b[0m"

struct				s_node
{
	char			*data;
	struct s_node	*next;
};

struct				node
{
	char			*data;
	struct node		*next;
};
/*
** Basic string functions ******************************************************
*/

int					listlen(struct node *root);
void				handle_signal(int signal);
char				*str_new(size_t size);
char				*str_dup(char *str);
char				*str_join(char *s1, char *s2);
char				**str_split(char *str, char d);
void				mem_for_str_split(char ***result, char *str, char deleimit);
void				str_clr(char *str);
void				str_del(char **str);
void				del_strs(char ***strs);
void				str_cpy(char *dst, char *src);
void				put_chr(char c);
void				put_str(char *str);
void				put_endl(char *str);
void				resize_str(char **str, size_t new_size);
size_t				str_len(char *str);
int					str_cmp(char *s1, char *s2);
int					ft_atoi(char *str);
int					str_chr(char *str, char c);
void				ft_putnbr(int nb);
size_t				ft_dstrlen(char **str);
size_t				ft_index(char *str);

/*
** Read input from stdin *******************************************************
*/

char				get_char(void);
char				*read_line(void);

/*
** Built-in functions **********************************************************
*/

void				func_help(void);
void				func_cd(char **args);
void				func_env(char **args);
void				func_export(char **args);
void				func_echo(char **args);
void				func_unset(char **args);

/*
** Find programs in PATH *******************************************************
*/

char				**get_path(void);
char				*found_in_path(char *name);

/*
** Execute commands ************************************************************
*/

void				execute_command(char **args);
void				launch_process(char **args);

/*
** Edit enviromental variables *************************************************
*/

int					set_env(const char *name, const char *value, int overwrite);
int					unset_env(const char *name);
char				*get_name(char *var);
char				*get_value(char *var);
void				print_environ(void);

/*
** Signals *********************************************************************
*/

void				handle_signal(int signal);

/*
** Multiple args ***************************************************************
*/

char				*minishell(void);
void				free_nodes(struct s_node *root);
struct s_node		*get_args(char *str);

/*
** Pipes ***********************************************************************
*/

int					execute_pipe(char *str);
int					ft_ispipe(char *temp);
int					ft_free2d(char **str);
void				freed(char ***str);
char				*add_color(char *str, char *color);

#endif
