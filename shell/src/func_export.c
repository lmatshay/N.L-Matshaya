/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:46:19 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:46:20 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	**get_pair(char *var)
{
	char	*name;
	char	**pair;
	int		loop;

	pair = (char**)malloc(sizeof(char*) * 3);
	if (pair == NULL)
		return (NULL);
	pair[2] = (char*)'\0';
	loop = 0;
	while (var[loop] != '\0' && var[loop] != '=')
		loop++;
	name = (char*)malloc(sizeof(char) * (loop + 1));
	if (name == NULL)
		return (NULL);
	name[loop] = '\0';
	pair[1] = str_dup(&(var[loop + 1]));
	loop = 0;
	while (var[loop] != '\0' && var[loop] != '=')
	{
		name[loop] = var[loop];
		loop++;
	}
	pair[0] = name;
	return (pair);
}

static char	***get_pairs(char **args)
{
	int		loop;
	char	***pairs;

	loop = 0;
	while (args[loop] != '\0')
		loop++;
	pairs = (char***)malloc(sizeof(char**) * (loop + 1));
	if (pairs == NULL)
		return (NULL);
	pairs[loop] = (char**)'\0';
	loop = 0;
	while (args[loop] != '\0')
	{
		pairs[loop] = get_pair(args[loop]);
		loop++;
	}
	return (pairs);
}

static void	free_pairs(char ****pairs)
{
	int	loop;

	loop = 0;
	while (pairs[0][loop] != '\0')
	{
		del_strs(&(pairs[0][loop]));
		loop++;
	}
	free(pairs[0]);
	pairs[0] = NULL;
}

void		func_export(char **args)
{
	char		***pairs;
	int			loop;

	loop = 0;
	pairs = get_pairs(args);
	if (pairs != NULL)
	{
		while (pairs[loop] != '\0')
		{
			set_env(pairs[loop][0], pairs[loop][1], 1);
			loop++;
		}
		free_pairs(&pairs);
	}
}
