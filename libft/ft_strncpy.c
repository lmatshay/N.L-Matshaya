/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:35:05 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/11 16:24:46 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;
	char	*d;
	const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < len)
	{
		if (*s == '\0')
			break ;
		*d++ = *s++;
		i++;
	}
	len = ft_strlen(dest);
	while (i < len)
	{
		if (*d)
			*d++ = '\0';
		i++;
	}
	return (dest);
}
