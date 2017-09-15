/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strcpy_2d(char **str)
{
	char	**newstr;
	int		i;

	i = 0;
	while (str[i])
		i++;
	newstr = (char **)malloc(sizeof(char *) * (i + 1));
	if (!newstr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		newstr[i] = ft_strdup(str[i]);
		i++;
	}
	newstr[i] = NULL;
	return (newstr);
}
