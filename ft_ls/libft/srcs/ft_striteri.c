/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:17:10 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:25:26 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		cpt;

	cpt = 0;
	if (s != NULL && f != NULL)
	{
		while (s[cpt])
		{
			f(cpt, &s[cpt]);
			cpt++;
		}
	}
}
