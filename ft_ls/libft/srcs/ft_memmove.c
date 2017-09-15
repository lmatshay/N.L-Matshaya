/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:09:20 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:09:26 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;

	if (len == 0 || dst == src)
		return (dst);
	tmp = (char *)malloc(sizeof(tmp) * len);
	ft_memcpy(tmp, src, len);
	ft_memcpy(dst, tmp, len);
	free(tmp);
	return ((void *)dst);
}
