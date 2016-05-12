/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:03:56 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/12 18:32:54 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*first;

	if (len == 0)
		return (b);
	first = (unsigned char *)b;
	while (len--)
	{
		*first = (unsigned char)c;
		if (len)
			first++;
	}
	return (b);
}
