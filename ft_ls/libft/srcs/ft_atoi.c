/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 12:49:10 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:03:23 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		rlt;
	int		sign;
	char	*tmp;

	rlt = 0;
	sign = 0;
	tmp = (char *)str;
	while (*tmp == '\t' || *tmp == '\n' || *tmp == '\v' || *tmp == '\f'
			|| *tmp == '\r' || *tmp == ' ')
		tmp++;
	sign = (*tmp == '-') ? -1 : 1;
	tmp = (*tmp == '+' || *tmp == '-') ? tmp + 1 : tmp;
	while (*tmp >= '0' && *tmp <= '9')
	{
		rlt = rlt * 10 + *tmp - 48;
		tmp++;
	}
	return (rlt * sign);
}
