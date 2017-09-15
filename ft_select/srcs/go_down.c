/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:34:43 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 01:37:47 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_go_down(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == (max - 1))
		select->pos = min;
	else
		select->pos = select->pos + 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}
