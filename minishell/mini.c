/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 08:47:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/06 15:50:11 by lmatshay         ###   ########.fr       */
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
	if (!args[1] || !args)
	{
		ft_putstr("There is no var to enter\n");
		return (1);
	}
	else
	{
		ft_putstr("Your var is been entered");
		setenv(args[1], args[2],1);
		ft_putstr("\n");
		return (1);
	}
}

int ft_unsetenv(char **args)
{
	if (!args[1] || !args)
	{
		ft_putstr("There is no var to enter\n");
		return (1);
	}
	else
	{
		ft_putstr("Your var is been removed");
		unsetenv(args[1]);
		ft_putstr("\n");
		return (1);
	}
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
