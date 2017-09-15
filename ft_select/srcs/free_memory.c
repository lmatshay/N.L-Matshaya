/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 00:45:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 01:59:41 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_free_mem(t_select *select)
{
	int		loop;

	loop = 0;
	while ((select->items)[loop] != '\0')
	{
		free((select->items)[loop]);
		loop++;
	}
	free(select->items);
	free(select->selected);
}
