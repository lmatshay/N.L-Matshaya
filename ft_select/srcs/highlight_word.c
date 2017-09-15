/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 21:36:19 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/15 21:40:21 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_highlight(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("so", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("se", NULL), 1, ft_put_char);
}
