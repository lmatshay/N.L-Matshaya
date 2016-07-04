/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 08:47:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/04 17:03:58 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "helpers.h"

int	ft_cd(char **args)
{
	if (args[1] == NULL)
		ft_putstr("expected argument to cd\n");
	else
	{
		if (chdir(args[1]) != 0)
			ft_putstr("An error has happened");
	}
	return (1);
}

int ft_help()
{
	int i;

	i = 0;
	while (i < num_builtins()) 
	{
		ft_putstr(builtin_str[i]);
		i++;
	}
	return (1);
}

int	ft_setenv(char **args)
{
		int		i;

		i = 0;
		ft_putstr("what");
		setenv(args[1],args[2],1);
		ft_putstr(args[1]);
		ft_putstr("\n");
		ft_putstr(args[2]);
		return (1);
}

int execute(char **args)
{
	int i;

	i = 0;
	if (args[0] == NULL)
	{
		return (1);
	}
	while (i++ < num_builtins()) 
	{
		if (ft_strcmp(args[0], builtin_str[i]) == 0) 
			return ((*builtin_func[i])(args));
	}
	return (launch(args));
}
