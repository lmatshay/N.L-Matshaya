/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:15 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:48:17 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_err(char *name)
{
	put_str(ANSI_COLOR_RED"error: cannot find command '"ANSI_COLOR_RESET);
	put_str(name);
	put_endl(ANSI_COLOR_RED"'"ANSI_COLOR_RESET);
}

static void	run_new(char **args, char **envp)
{
	char	*path;

	if (access(args[0], F_OK) == -1)
	{
		path = found_in_path(args[0]);
		if (path != NULL)
		{
			execve(path, args, envp);
			str_del(&path);
		}
		else
		{
			print_err(args[0]);
			exit(0);
		}
	}
	else
		execve(args[0], args, envp);
}

void		launch_process(char **args)
{
	pid_t		pid;
	extern char	**environ;
	int			stat;

	pid = fork();
	if (pid == 0)
	{
		run_new(args, environ);
	}
	else if (pid < 0)
		put_endl(ANSI_COLOR_RED"error could not start process"ANSI_COLOR_RESET);
	else
	{
		waitpid(pid, &stat, WUNTRACED);
		while (!WIFEXITED(stat) && !WIFSIGNALED(stat))
			waitpid(pid, &stat, WUNTRACED);
	}
}
