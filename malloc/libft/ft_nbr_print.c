/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_oct_nbr(unsigned int i, int *n)
{
	char	c;

	if (i >= 8)
	{
		ft_print_oct_nbr(i / 8, n);
		ft_print_oct_nbr(i % 8, n);
	}
	else
	{
		c = 48 + i;
		write(1, &c, 1);
		(*n)++;
	}
}

void	ft_print_oct(va_list *arg, int *n)
{
	unsigned int	i;

	i = va_arg((*arg), unsigned int);
	ft_print_oct_nbr(i, n);
}

void	ft_print_uns_nbr(unsigned int i, int *n)
{
	char	c;

	if (i >= 10)
	{
		ft_print_uns_nbr(i / 10, n);
		ft_print_uns_nbr(i % 10, n);
	}
	else
	{
		c = 48 + i;
		write(1, &c, 1);
		(*n)++;
	}
}

void	ft_print_uns(va_list *arg, int *n)
{
	unsigned int	i;

	i = va_arg((*arg), unsigned int);
	ft_print_uns_nbr(i, n);
}
