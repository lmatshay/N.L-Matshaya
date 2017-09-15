/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_item.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:45:43 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 16:33:30 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_swap_arrs(t_select *select, char **new_s, int *new_i)
{
	int		loop;

	loop = 0;
	while ((select->items)[loop] != '\0')
		free((select->items)[loop++]);
	free((select->items));
	free(select->selected);
	if (select->pos == select->n_items - 1)
		select->pos--;
	(select->n_items)--;
	if (select->n_items == 0)
	{
		ft_reset_term_behavior(&(select->term));
		exit(0);
	}
	select->items = new_s;
	select->selected = new_i;
}

static void		ft_delete_item(t_select *select)
{
	char	**new_list;
	int		*new_selection;
	int		pos;
	int		items;
	int		loop;

	pos = 0;
	items = select->n_items;
	new_list = (char**)malloc(sizeof(char*) * items);
	new_selection = (int*)malloc(sizeof(int) * items);
	new_list[items - 1] = (char*)'\0';
	new_selection[items - 1] = (int)'\0';
	loop = 0;
	while (pos < items)
	{
		if (pos != select->pos)
		{
			new_list[loop] = ft_strdup(select->items[pos]);
			new_selection[loop] = (select->selected)[pos];
			loop++;
		}
		pos++;
	}
	ft_swap_arrs(select, new_list, new_selection);
}

void			ft_remove_item(t_select *select)
{
	ft_delete_item(select);
	ft_save_and_load(select, 0);
	ft_print_list(select);
}
