/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 11:41:00 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/11 12:10:27 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*add_color(char *str, char *color)
{
	char		*temp;
	char		*final;

	final = NULL;
	if (str && color)
	{
		temp = str_join(color, str);
		if (temp)
		{
			final = str_join(temp, ANSI_COLOR_RESET);
			free(temp);
		}
		free(str);
	}
	return (final);
}
