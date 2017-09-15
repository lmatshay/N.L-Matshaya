/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:39:52 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:39:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	loop;

	num = 0;
	sign = 1;
	loop = 0;
	if (str[loop] == '-')
	{
		loop++;
		sign = -1;
	}
	while (str[loop] != '\0')
	{
		if (str[loop] >= '0' && str[loop] <= '9')
			num = (num * 10) + (int)(str[loop] - '0');
		else
			return (num * sign);
		loop++;
	}
	return (num * sign);
}
