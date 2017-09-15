/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:31 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:58 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	unsigned int	i;
	int				j;

	i = 0;
	if (s2[i] == 0)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (&((char *)s1)[i - j]);
			i++;
			j++;
		}
		i++;
	}
	return (NULL);
}
