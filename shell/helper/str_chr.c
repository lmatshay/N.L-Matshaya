/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:41:37 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:41:38 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		str_chr(char *str, char c)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
	{
		if (str[loop] == c)
			return (1);
		loop++;
	}
	return (-1);
}
