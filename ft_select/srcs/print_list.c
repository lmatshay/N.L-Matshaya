/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 00:50:03 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 10:09:06 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_check_winsize(t_select *select)
{
	int		i;

	i = ft_get_longest_item(select);
	if (select->win.ws_row <= select->n_items || select->win.ws_col <= i)
	{
		if (select->win.ws_row <= select->n_items)
			ft_put_endl("* Window height is too small.");
		if (select->win.ws_col <= i)
			ft_put_endl("* Window width is too small.");
		return (-1);
	}
	return (1);
}

void		ft_print_list(t_select *select)
{
	int		lp;

	lp = 0;
	ft_clear_terminal();
	if (ft_check_winsize(select) == -1)
		return ;
	while ((select->items)[lp] != '\0')
	{
		if (select->pos == lp)
		{
			if (select->selected[lp] == 1)
				ft_put_underline_highlight((select->items)[lp], ft_put_magneta);
			else
				ft_put_underline((select->items)[lp], ft_put_cyan);
		}
		else
		{
			if (select->selected[lp] == 1)
				ft_put_highlight((select->items)[lp], ft_put_cyan);
			else
				ft_put_endl((select->items)[lp]);
		}
		lp++;
	}
}
