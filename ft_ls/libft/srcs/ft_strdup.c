/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:16:26 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:16:31 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char				*ft_strdup(const char *s1)
{
	size_t			i;
	char			*rlt;
	size_t			str_len;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	str_len = ft_strlen(s1);
	rlt = (char*)malloc(str_len + 1);
	if (!rlt)
		return (NULL);
	while (i < str_len)
	{
		rlt[i] = s1[i];
		i++;
	}
	rlt[i] = '\0';
	return (rlt);
}
