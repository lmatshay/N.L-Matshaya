/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_to_term.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 22:24:50 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/16 00:07:03 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_reset_term_behavior(struct termios *term)
{
	tputs(tgetstr("ve", NULL), 1, ft_put_char);
	tputs(tgetstr("te", NULL), 1, ft_put_char);
	term->c_lflag |= (ICANON | ECHO);
	if ((tcsetattr(FILE_DS, TCSANOW, term)) == -1)
		return (-1);
	return (0);
}
