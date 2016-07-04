/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:47:06 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/04 16:39:05 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*newptr;

	if (!size && ptr)
	{
		if (!(newptr = (char *)malloc(1)))
  			return (NULL);
		ft_memdel(&ptr);
		return (newptr);
	}
	if (!(newptr = (char *)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(newptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (newptr);
}

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*d;
	const char	*s;

	if (n)
	{
		d = (char*)s1;
		s = (const char*)s2;
		while (n--)
			*(d++) = *(s++);
	}
	return (s1);
}
