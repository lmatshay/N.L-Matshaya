/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_behavior.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:13:30 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 00:06:44 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_change_term_behavior(struct termios *term)
{
	if (tgetent(NULL, getenv("TERM")) == -1)
		return (-1);
	if (tcgetattr(FILE_DS, term) == -1)
		return (-1);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(FILE_DS, TCSANOW, term) == -1)
		return (-1);
	tputs(tgetstr("ti", NULL), 1, ft_put_char);
	tputs(tgetstr("vi", NULL), 1, ft_put_char);
	return (0);
}
