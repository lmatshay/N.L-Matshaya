/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 08:28:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/11 11:38:51 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		**put_in_ss(char *str)
{
	char	**arg;

	if (str)
	{
		arg = str_split(str, '|');
		if (arg)
			return (arg);
	}
	return (NULL);
}

static char		***put_in_sss(char **str)
{
	char	***args;
	char	***arg;
	char	**temp;
	int		len;

	temp = str;
	len = ft_dstrlen(str);
	if (str)
	{
		arg = (char ***)malloc(sizeof(char **) * (len + 2));
		args = arg;
		if (arg)
		{
			while (*temp)
			{
				*arg = str_split(*temp, ' ');
				arg++;
				temp++;
			}
			*arg = NULL;
			return (args);
		}
	}
	return (NULL);
}

static void		helper(char ***cmd, pid_t pid, int fd_in, int *p)
{
	while (*cmd)
	{
		pipe(p);
		if ((pid = fork()) == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			dup2(fd_in, 0);
			if (*(cmd + 1))
				dup2(p[1], 1);
			close(p[0]);
			execvp((*cmd)[0], *cmd);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
			close(p[1]);
			fd_in = p[0];
			cmd++;
		}
	}
}

static void		loop_pipe(char ***cmd)
{
	pid_t		pid;
	int			p[2];
	int			fd_in;

	fd_in = 0;
	pid = 0;
	if (!cmd)
	{
		put_str(ANSI_COLOR_RED"str passed to pipe is 'NULL'"ANSI_COLOR_RESET);
	}
	else
	{
		helper(cmd, pid, fd_in, p);
	}
}

int				execute_pipe(char *str)
{
	char	**put_in_sst;
	char	***temp;

	if (str)
	{
		put_in_sst = put_in_ss(str);
		if (put_in_sst)
		{
			temp = put_in_sss(put_in_sst);
			if (temp)
			{
				loop_pipe(temp);
				freed(temp);
			}
			ft_free2d(put_in_sst);
		}
		return (1);
	}
	else
		put_str(ANSI_COLOR_RED"str passed to pipe is 'NULL'"ANSI_COLOR_RESET);
	return (0);
}
