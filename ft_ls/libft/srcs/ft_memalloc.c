/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:07:10 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:07:15 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size != 0)
	{
		tmp = malloc(size);
		if (tmp != NULL)
			ft_bzero(tmp, size);
		return (tmp);
	}
	return (NULL);
}
