/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:45:44 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:45:46 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		echo_env(char *arg)
{
	char	*str;

	str = get_value(arg);
	if (str != NULL)
		put_str(str);
}

static void		func_print(char **args, int i, int k)
{
	while (args[i] != NULL)
	{
		k = 0;
		if (str_cmp(args[i], "-n") == 0)
			i++;
		if (args[i][0] == '$')
			echo_env(&(args[i][1]));
		while (args[i][k] != '\0' && args[i][0] != '$')
		{
			if (args[i] == args[0])
				i++;
			write(1, &args[i][k], 1);
			k++;
		}
		write(1, " ", 1);
		i++;
	}
}

static void		echo_loop(char **args, int k)
{
	while (args[1][k] != '\0')
	{
		write(1, &args[1][k], 1);
		k++;
	}
}

static int		test_(char **args)
{
	if (args[1] == NULL)
	{
		put_chr('\n');
		return (1);
	}
	return (-1);
}

void			func_echo(char **args)
{
	int				i;
	int				k;

	k = 0;
	i = 1;
	if (test_(args) == 1)
		return ;
	else
	{
		if (args[1] && !(args[2]))
		{
			if (str_cmp(args[1], "-n") == 0)
				return ;
			if (args[1][0] == '$')
				echo_env(&args[1][1]);
			else
				echo_loop(args, k);
		}
		else
			func_print(args, i, k);
	}
	if (str_cmp(args[1], "-n") != 0)
		write(1, "\n", 1);
}
