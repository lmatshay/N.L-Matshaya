/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		l;
	char	*map;
	char	*ss;

	ss = (char *)s;
	l = 0;
	if (ss != NULL)
	{
		while (ss[l])
			l++;
	}
	if ((map = (char *)malloc(l + 1)) == NULL)
		return (NULL);
	i = 0;
	if (ss != NULL && f != NULL)
	{
		while (ss[i])
		{
			map[i] = f(i, ss[i]);
			i++;
		}
	}
	map[i] = '\0';
	return (map);
}
