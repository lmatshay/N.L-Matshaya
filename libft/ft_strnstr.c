/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 13:01:16 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/08 13:01:18 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!s2)
		return ((char*)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j] && s2[j] && (i + j) < n)
			j++;
		if (s2[j] == '\0')
			return ((char*)(s1 + i));
		j = 0;
		i++;
	}
	return (NULL);
}
