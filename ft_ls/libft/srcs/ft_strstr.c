/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:39:41 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:39:46 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strstr(const char *s1, const char *s2)
{
	const char	*tmp;
	const char	*tmp_2;

	tmp_2 = s2;
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		tmp = s1;
		while (*tmp == *tmp_2)
		{
			tmp++;
			tmp_2++;
			if (*tmp_2 == '\0')
				return ((char*)s1);
		}
		tmp_2 = s2;
		s1++;
	}
	return (NULL);
}
