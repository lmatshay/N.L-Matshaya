/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hidenp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 12:51:50 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/11 12:51:55 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_hidenp(char *hiden, char *str)
{
	int		cpt;
	int		cpt_str;

	cpt = 0;
	cpt_str = 0;
	while (str[cpt_str] != '\0')
	{
		if (str[cpt_str] == hiden[cpt])
			cpt++;
		if (hiden[cpt] == '\0')
			return (1);
		cpt_str++;
	}
	return (0);
}
