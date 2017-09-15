/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:45:22 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/02 11:37:26 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_err(char *dir)
{
	put_str(ANSI_COLOR_RED"error: could not change to '"ANSI_COLOR_RESET);
	put_str(ANSI_COLOR_GREEN);
	put_str(dir);
	put_str(ANSI_COLOR_RESET);
	put_endl(ANSI_COLOR_RED"' directory"ANSI_COLOR_RESET);
}

static void	change_dir(char *path)
{
	char	*old_pwd;
	char	*new_pwd;

	old_pwd = str_new(1024);
	getcwd(old_pwd, 1024);
	if (chdir(path) != 0)
		print_err(path);
	else
	{
		new_pwd = str_new(1024);
		getcwd(new_pwd, 1024);
		if (old_pwd != NULL && new_pwd != NULL)
		{
			set_env("OLDPWD", old_pwd, 1);
			set_env("PWD", new_pwd, 1);
			str_del(&old_pwd);
			str_del(&new_pwd);
		}
		else
			unset_env("OLDPWD");
	}
}

static void	handle_home(char **args)
{
	char	*home;
	char	*tmp;

	home = get_value("HOME");
	if (home != NULL)
	{
		if (args[1] == NULL || str_len(args[1]) == 1)
			change_dir(home);
		else
		{
			tmp = str_join(home, "/");
			home = str_join(tmp, &(args[1][2]));
			change_dir(home);
			str_del(&tmp);
		}
		str_del(&home);
	}
}

void		func_cd(char **args)
{
	char	*last_dir;

	if (args[1] != NULL && args[1][0] != '~')
	{
		if (args[1][0] == '-')
		{
			last_dir = get_value("OLDPWD");
			if (last_dir == NULL)
				put_endl("error: OLDPWD not set");
			else
			{
				change_dir(last_dir);
				put_endl(last_dir);
				str_del(&last_dir);
			}
		}
		else
			change_dir(args[1]);
	}
	else
		handle_home(args);
}
