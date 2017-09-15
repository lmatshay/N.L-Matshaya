/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:12:39 by mmacheke          #+#    #+#             */
/*   Updated: 2016/06/12 07:12:45 by mmacheke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putunbr(unsigned int n)
{
	if (n > 9)
		ft_putunbr(n / 10);
	ft_putchar((n % 10) + '0');
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putunbr(-n);
	}
	else
		ft_putunbr(n);
}
