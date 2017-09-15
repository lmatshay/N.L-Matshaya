/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:08:35 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:08:40 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*save_ptr;
	const char	*save_ptr_2;

	i = 0;
	save_ptr = s1;
	save_ptr_2 = s2;
	while (i < n)
	{
		*save_ptr = *save_ptr_2;
		save_ptr++;
		save_ptr_2++;
		i++;
	}
	return (s1);
}
