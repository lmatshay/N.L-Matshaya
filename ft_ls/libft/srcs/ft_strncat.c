/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:18:49 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:18:54 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	char		*tmp;

	tmp = s1;
	if (!s1 || !s2)
		return (NULL);
	while (*s1)
		s1++;
	while (n > 0 && *s2)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = '\0';
	return (tmp);
}
