/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellname.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/02 12:08:58 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/11 11:48:32 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char		*get_sh(void)
{
	char		*sh;
	char		*temp;

	sh = NULL;
	temp = str_join(ANSI_COLOR_CYAN, "@wethinkcode_:");
	if (temp)
	{
		sh = str_join(temp, ANSI_COLOR_RESET);
		str_del(&temp);
	}
	return (sh);
}

static char		*get_pwd(void)
{
	char		*pwd;
	char		*temp;

	temp = get_value("PWD");
	pwd = NULL;
	if (temp)
	{
		pwd = str_join(temp, "$> ");
		if (pwd)
		{
			str_del(&temp);
			return (add_color(pwd, ANSI_COLOR_GREEN));
		}
		str_del(&temp);
	}
	else
	{
		if ((temp = (char *)malloc(19)))
		{
			str_cpy(temp, "/environ-not-set$ ");
			temp[18] = '\0';
			pwd = add_color(temp, ANSI_COLOR_RED);
		}
	}
	return (pwd);
}

static char		*usr_helper(void)
{
	char		*temp;
	char		*sh;

	temp = NULL;
	sh = NULL;
	if ((temp = (char *)malloc(18)))
	{
		str_cpy(temp, "environ-not-set_:");
		temp[17] = '\0';
		sh = add_color(temp, ANSI_COLOR_RED);
	}
	return (sh);
}

static char		*get_usr(void)
{
	char		*usr;
	char		*sh;
	char		*temp;

	temp = get_value("LOGNAME");
	sh = NULL;
	if (temp)
	{
		if ((sh = get_sh()))
		{
			temp = add_color(temp, ANSI_COLOR_YELLOW);
			usr = str_join(temp, sh);
			if (usr)
			{
				str_del(&temp);
				str_del(&sh);
				return (usr);
			}
		}
		str_del(&temp);
		str_del(&sh);
	}
	else
		sh = usr_helper();
	return (sh);
}

char			*minishell(void)
{
	char		*final;
	char		*pwd;
	char		*usr;

	final = NULL;
	pwd = get_pwd();
	usr = get_usr();
	if (pwd && usr)
	{
		final = str_join(usr, pwd);
		str_del(&pwd);
		str_del(&usr);
	}
	return (final);
}
