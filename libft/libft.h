/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 08:41:06 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/12 18:41:30 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putchar(char c);
void	ft_putnbr(int c);
void	ft_putstr(char const *s);
int		ft_isalpha(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putchar_fd(char c, int fd);
char	*ft_strcat(char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	ft_memset(void *b, int c, size_t len);

#endif
