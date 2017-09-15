/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 23:10:07 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 10:23:54 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_clr(char *str)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		str[loop++] = '\0';
}

void			ft_keyhook(void)
{
	char	key[5];

	key[4] = '\0';
	while (1)
	{
		ft_clr(key);
		read(0, key, 4);
		if (key[0] == 27 && key[1] == '\0' && key[2] == '\0')
			return ;
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'A')
			ft_go_up(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 'B')
			ft_go_down(ft_save_and_load(NULL, 1));
		else if (key[0] == 32 && key[1] == '\0' && key[2] == '\0')
			ft_select_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 10 && key[1] == '\0' && key[2] == '\0')
			ft_enter(ft_save_and_load(NULL, 1));
		else if (key[0] == 127 && key[1] == '\0' && key[2] == '\0')
			ft_remove_item(ft_save_and_load(NULL, 1));
		else if (key[0] == 27 && key[1] == 91 && key[2] == 51)
			ft_remove_item(ft_save_and_load(NULL, 1));
	}
}
