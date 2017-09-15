/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 09:19:03 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 09:19:07 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_win_change(void)
{
	t_select	*tmp;

	tmp = ft_save_and_load(NULL, 1);
	ioctl(FILE_DS, TIOCGWINSZ, &(tmp->win));
	ft_save_and_load(tmp, 0);
	ft_print_list(tmp);
}
