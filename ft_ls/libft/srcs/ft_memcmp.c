/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:08:11 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:08:16 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp;
	const unsigned char	*tmp_2;

	if (n == 0)
		return (0);
	tmp = s1;
	tmp_2 = s2;
	while (n--)
	{
		if (*tmp != *tmp_2)
			return (*tmp - *tmp_2);
		tmp++;
		tmp_2++;
	}
	return (0);
}
