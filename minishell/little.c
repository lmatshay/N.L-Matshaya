/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 15:19:18 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/06 15:44:41 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_exit()
{
	return (0);
}

char	get_char(void)
{
	char	c;

	read(0, &c, 1);
	return (c);
}
