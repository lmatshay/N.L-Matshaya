/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:07:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:07:54 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*tmp;

	i = 0;
	if (s != NULL)
	{
		tmp = s;
		while (i < n)
		{
			if (ft_memcmp(tmp, &c, 1) == 0)
				return ((void*)tmp);
			i++;
			tmp++;
		}
	}
	return (NULL);
}
