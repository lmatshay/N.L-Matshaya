/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:09:44 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:09:50 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = b;
	while ((i < len) && (b != NULL))
	{
		*tmp = c;
		i++;
		tmp++;
	}
	return (b);
}
