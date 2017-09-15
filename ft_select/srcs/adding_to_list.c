/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 00:38:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 16:11:16 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_add_list(t_select *select, int n, char **list)
{
	int		loop;

	loop = 0;
	select->items = (char**)malloc(sizeof(char*) * (n + 1));
	select->selected = (int*)malloc(sizeof(int) * (n + 1));
	if (select->items == NULL || select->selected == NULL)
		return ;
	(select->items)[n] = (char*)'\0';
	(select->selected)[n] = (int)'\0';
	select->n_items = n;
	select->pos = 0;
	while (loop < n)
	{
		(select->items)[loop] = ft_strdup(list[loop]);
		loop++;
	}
	ioctl(FILE_DS, TIOCGWINSZ, &(select->win));
}
