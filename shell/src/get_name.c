/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:47:13 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:47:14 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_name(char *var)
{
	int		loop;
	char	*name;

	loop = 0;
	while (var[loop] != '\0' && var[loop] != '=')
		loop++;
	name = str_new(loop);
	if (name == NULL)
		return (NULL);
	loop = 0;
	while (var[loop] != '\0' && var[loop] != '=')
	{
		name[loop] = var[loop];
		loop++;
	}
	name[loop] = '\0';
	return (name);
}
