/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 03:23:52 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 18:24:40 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_enter(t_select *select)
{
	int		loop;

	loop = 0;
	ft_reset_term_behavior(&(select->term));
	while (select->n_items > loop)
	{
		if ((select->selected)[loop] == 1)
		{
			ft_put_str_fd((select->items)[loop], 1);
			ft_put_char_fd(' ', 1);
		}
		loop++;
	}
	ft_put_char_fd('\n', 1);
	exit(0);
}
