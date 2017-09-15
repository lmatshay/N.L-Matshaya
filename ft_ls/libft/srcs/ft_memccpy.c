/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:07:28 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:07:33 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tmp_dst;
	char		*tmp_src;

	if (dst && src)
	{
		tmp_dst = (char*)dst;
		tmp_src = (char*)src;
		while (n > 0)
		{
			*tmp_dst = *tmp_src;
			tmp_dst++;
			if (*tmp_src == c)
				return (tmp_dst);
			tmp_src++;
			n--;
		}
	}
	return (NULL);
}
