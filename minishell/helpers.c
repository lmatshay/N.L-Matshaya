/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 12:12:23 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/06 14:39:16 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (1);
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((int)(unsigned char)*s1 - *s2);
		++s1;
		++s2;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char *s)
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		ft_putchar(s[i]);
	return (0);
}

int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) 
	{
		if (execvp(args[0], args) < 0)   
		{
			ft_putstr("You have typed an invald command, please check\n");
			exit(EXIT_FAILURE);
		} 
	 if (pid < 0) 
		{
			ft_putstr("Something happened, don't freak out");
		}
	}
	else 
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	waitpid(pid, &status, WUNTRACED);
	return (1);
}


