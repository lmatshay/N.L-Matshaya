/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:49:00 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:49:01 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		count_names(char **envp, char *var)
{
	int		count;
	int		loop;
	char	*name;

	count = 0;
	loop = 0;
	while (envp[loop] != '\0')
	{
		name = get_name(envp[loop]);
		if (str_cmp(name, var) == 0)
			count++;
		loop++;
		str_del(&name);
	}
	return (count);
}

static char		**edit_environ(char **envp, char *name)
{
	int		loop;
	int		loop2;
	int		found;
	char	**result;
	char	*var_name;

	loop = 0;
	loop2 = 0;
	found = count_names(envp, name);
	while (envp[loop] != '\0')
		loop++;
	result = (char**)malloc(sizeof(char*) * ((loop - found) + 1));
	result[loop - found] = (char*)'\0';
	loop = 0;
	while (envp[loop2] != '\0')
	{
		var_name = get_name(envp[loop2]);
		if (str_cmp(var_name, name) != 0)
			result[loop++] = str_dup(envp[loop2]);
		loop2++;
		str_del(&var_name);
	}
	return (result);
}

static void		free_env(char ***envp)
{
	int	loop;

	loop = 0;
	while (envp[0][loop] != '\0')
	{
		str_del(&(envp[0][loop]));
		loop++;
	}
	free(envp[0]);
	envp[0] = NULL;
}

int				unset_env(const char *name)
{
	static int	edited = -1;
	extern char	**environ;
	char		**tmp;

	if (edited == -1)
	{
		environ = edit_environ(environ, (char*)name);
		edited = 1;
	}
	else if (edited == 1)
	{
		tmp = environ;
		environ = edit_environ(environ, (char*)name);
		free_env(&tmp);
	}
	return (0);
}
