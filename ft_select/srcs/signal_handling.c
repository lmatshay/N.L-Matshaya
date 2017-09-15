/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:58:00 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 01:03:00 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ft_handle(int num)
{
	t_select	*select;
	char		ch[2];

	if (num == SIGINT)
		ft_exit();
	else if (num == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		select = ft_save_and_load(NULL, 1);
		ft_reset_term_behavior(&(select->term));
		ch[0] = select->term.c_cc[VSUSP];
		ch[1] = '\0';
		ioctl(0, TIOCSTI, ch);
	}
	else if (num == SIGCONT)
	{
		signal(SIGTSTP, ft_handle);
		select = ft_save_and_load(NULL, 1);
		ft_change_term_behavior(&(select->term));
		ft_print_list(select);
	}
	else if (num == SIGWINCH)
		ft_win_change();
	else
		ft_exit();
}

void			ft_handle_signals(void)
{
	int		loop;

	loop = 1;
	while (loop <= 31)
		signal(loop++, ft_handle);
}
