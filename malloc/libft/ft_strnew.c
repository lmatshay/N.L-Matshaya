/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:54 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(size) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	while (new[i])
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
