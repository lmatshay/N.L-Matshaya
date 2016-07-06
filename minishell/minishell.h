/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 08:02:17 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/06 15:44:27 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
#define LINE_BUFSIZE 1500
# define BUFSIZE 1000

char	*ft_read_line_sub(int bufsize, char *buffer, int c, int position);
char **ft_line_sub(char **tokens, int position, char *token, int bufsize);
int	ft_putstr(char *s);
int ft_help(char **args);
int	ft_unsetenv(char **args);
int ft_exit(char **args);
int num_builtins();
int ft_cd(char **args);
int ft_help(char **args);
int ft_exit(char **args);
int launch(char **args);
char	get_char(void);
int execute(char **args);
char 	*read_line(void);
int	ft_setenv(char **args);
char **ft_line(char *line);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	ft_memdel(void	**ap);


# endif
