/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 01:16:48 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 01:32:52 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_go_up(t_select *select)
{
	int		current;
	int		max;
	int		min;

	current = select->pos;
	max = select->n_items;
	min = 0;
	if (current == min)
		select->pos = max - 1;
	else
		select->pos = select->pos - 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}
