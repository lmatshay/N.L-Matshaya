/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 00:19:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 00:36:14 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_strlen(char *str)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		loop++;
	return (loop);
}

char		*ft_strdup(char *str)
{
	int		len;
	char	*tmp;

	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	tmp[len] = '\0';
	len = 0;
	while (str[len] != '\0')
	{
		tmp[len] = str[len];
		len++;
	}
	return (tmp);
}
