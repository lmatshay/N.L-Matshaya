/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:44:58 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:44:59 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_command(char **args)
{
	if (str_cmp("cd", args[0]) == 0)
		func_cd(args);
	else if (str_cmp("help", args[0]) == 0)
		func_help();
	else if (str_cmp("echo", args[0]) == 0)
		func_echo(args);
	else if (str_cmp("export", args[0]) == 0)
		func_export(&(args[1]));
	else if (str_cmp("unset", args[0]) == 0)
		func_unset(args);
	else if (str_cmp("env", args[0]) == 0)
		func_env(args);
	else
		launch_process(args);
}
