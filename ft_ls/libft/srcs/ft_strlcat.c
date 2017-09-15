/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:17:43 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:19:24 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;
	size_t		len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst)
		return (len_src + size);
	while (*dst != '\0' && size--)
		dst++;
	while (size-- > 1 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (len_dst + len_src);
}
