/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:56:12 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/08 12:56:15 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t len;

	len = ft_strlen(dst);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	if (size < len)
		return (ft_strlen(src) + size);
	if (size == len)
		return (len + ft_strlen(src));
	else
	{
		while (src[j] && j < size - len - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (len + ft_strlen(src));
	}
}
