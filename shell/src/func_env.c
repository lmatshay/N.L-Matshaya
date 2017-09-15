/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:46:01 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:46:02 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		count_vars(char **args)
{
	int		loop;
	int		count;

	loop = 0;
	count = 0;
	while (args[loop] != '\0')
	{
		if (str_chr(args[loop], '=') == 1)
			count++;
		loop++;
	}
	return (count);
}

static void		unset_all(char **pairs)
{
	int		loop;
	char	**names;

	loop = 0;
	while (pairs[loop] != '\0')
		loop++;
	names = (char**)malloc(sizeof(char*) * (loop + 1));
	names[loop] = (char*)'\0';
	loop = 0;
	while (pairs[loop] != '\0')
	{
		names[loop] = get_name(pairs[loop]);
		loop++;
	}
	func_unset(names);
	del_strs(&names);
}

void			func_env(char **args)
{
	int		vars;
	int		loop;
	char	**pairs;

	if (args[1] == NULL)
		print_environ();
	else
	{
		vars = count_vars(args);
		loop = 0;
		pairs = (char**)malloc(sizeof(char*) * (vars + 1));
		pairs[vars] = (char*)'\0';
		while (loop < vars)
		{
			pairs[loop] = str_dup(args[loop + 1]);
			loop++;
		}
		func_export(pairs);
		execute_command(&(args[vars + 1]));
		unset_all(pairs);
		del_strs(&pairs);
	}
}
