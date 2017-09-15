/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_item_in_term.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 09:44:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 10:14:25 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	ft_strlen(char *str)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		loop++;
	return (loop);
}

int			ft_get_longest_item(t_select *select)
{
	int		loop;
	int		len;
	int		i;

	loop = 0;
	if (select->n_items <= 0)
		return (0);
	len = ft_strlen((select->items)[0]);
	while ((select->items)[loop] != '\0')
	{
		i = ft_strlen((select->items)[loop]);
		if (len <= i)
			len = i;
		loop++;
	}
	return (len);
}
