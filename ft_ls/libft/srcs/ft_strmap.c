/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:18:16 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:18:21 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		cpt;
	char	*new;

	cpt = 0;
	new = NULL;
	if (s != NULL && f != NULL)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (new != NULL)
		{
			while (s[cpt])
			{
				new[cpt] = f(s[cpt]);
				cpt++;
			}
			new[cpt] = '\0';
		}
	}
	return (new);
}
