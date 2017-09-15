/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:46 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:48:47 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		found_name(char **envp, const char *name)
{
	int		loop;
	char	*tmp;

	loop = 0;
	while (envp[loop] != '\0')
	{
		tmp = get_name(envp[loop]);
		if (str_cmp((char*)name, tmp) == 0)
		{
			str_del(&tmp);
			return (1);
		}
		str_del(&tmp);
		loop++;
	}
	return (-1);
}

static char		**set_name(char **envp, const char *name, const char *value)
{
	int		loop;
	char	**new_env;
	char	*tmp;

	loop = 0;
	while (envp[loop] != '\0')
		loop++;
	loop++;
	new_env = (char**)malloc(sizeof(char*) * (loop + 1));
	new_env[loop] = (char*)'\0';
	loop = 0;
	while (envp[loop] != '\0')
	{
		new_env[loop] = str_dup(envp[loop]);
		loop++;
	}
	tmp = str_join((char*)name, "=");
	new_env[loop] = str_join(tmp, (char*)value);
	str_del(&tmp);
	return (new_env);
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

static void		setenv_(char ***envp, const char *n, const char *v, int *e)
{
	char	**tmp;

	if (e[0] == -1)
	{
		unset_env(n);
		envp[0] = set_name(envp[0], n, v);
		e[0] = 1;
	}
	else if (e[0] == 1)
	{
		unset_env(n);
		tmp = envp[0];
		envp[0] = set_name(envp[0], n, v);
		free_env(&tmp);
	}
}

int				set_env(const char *name, const char *value, int overwrite)
{
	static int	edited = -1;
	extern char	**environ;
	char		**tmp;

	if (found_name(environ, name) == 1)
	{
		if (overwrite != 0)
			setenv_(&environ, name, value, &edited);
	}
	else
	{
		if (edited == -1)
		{
			environ = set_name(environ, name, value);
			edited = 1;
		}
		else if (edited == 1)
		{
			tmp = environ;
			environ = set_name(environ, name, value);
			free_env(&tmp);
		}
	}
	return (0);
}
