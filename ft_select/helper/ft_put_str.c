/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 21:07:08 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/15 21:08:46 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_str(char *str)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		ft_put_char((int)str[loop++]);
}