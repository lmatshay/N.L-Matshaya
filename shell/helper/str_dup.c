/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:42:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:42:49 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*str_dup(char *str)
{
	int		loop;
	char	*new;

	loop = 0;
	new = str_new(str_len(str));
	if (new != NULL)
	{
		while (str[loop] != '\0')
		{
			new[loop] = str[loop];
			loop++;
		}
		new[loop] = '\0';
	}
	return (new);
}
