/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_item.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 02:05:31 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 02:59:42 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_select_item(t_select *select)
{
	int		pos;

	pos = select->pos;
	if (select->selected[pos] == 1)
		select->selected[pos] = -1;
	else
		select->selected[pos] = 1;
	if (select->pos == select->n_items - 1)
		select->pos = 0;
	else
		select->pos += 1;
	ft_save_and_load(select, 0);
	ft_print_list(select);
}
