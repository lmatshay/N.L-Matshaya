/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_and_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:40:19 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/15 22:42:31 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*ft_save_and_load(t_select *select, int mode)
{
	static t_select	*tmp = NULL;

	if (mode == 0)
		tmp = select;
	return (tmp);
}
