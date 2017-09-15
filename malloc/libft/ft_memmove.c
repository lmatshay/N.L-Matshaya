/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*ss1;
	const char	*ss2;

	ss1 = s1;
	ss2 = s2;
	if (ss1 >= ss2)
	{
		ss1 += n - 1;
		ss2 += n - 1;
		while (n > 0)
		{
			*ss1 = *ss2;
			ss1--;
			ss2--;
			n--;
		}
	}
	else
		ft_memcpy(s1, s2, n);
	return (s1);
}
