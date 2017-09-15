/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:35:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:35:41 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_puttbl(unsigned int n, char *len_sign, char **str, size_t b)
{
	int		cpt;
	char	*tbl_b;

	tbl_b = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (n > (b - 1))
	{
		len_sign[0] += 1;
		cpt = ft_puttbl(n / b, len_sign, str, b);
	}
	else
	{
		*str = ft_strnew(len_sign[0]);
		cpt = len_sign[1];
	}
	if (*str != NULL)
		(*str)[cpt] = tbl_b[(n % b)];
	return (cpt + 1);
}

char			*ft_itoa_base(int n, int b)
{
	char	*str;
	char	*len_sign;

	str = NULL;
	len_sign = ft_strnew(2);
	if (b >= 2 && b <= 36)
	{
		if (n < 0)
		{
			len_sign[0] = 1;
			len_sign[1] = 1;
			ft_puttbl(-n, len_sign, &str, b);
			if (str != NULL)
				str[0] = '-';
		}
		else
		{
			len_sign[0] = 0;
			len_sign[1] = 0;
			ft_puttbl(n, len_sign, &str, b);
		}
	}
	return (str);
}
