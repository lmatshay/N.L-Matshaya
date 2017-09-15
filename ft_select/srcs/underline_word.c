/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underline_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 21:30:28 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/15 21:33:59 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_underline(char *str, void (*ft_print)(char*))
{
	tputs(tgetstr("us", NULL), 1, ft_put_char);
	(*ft_print)(str);
	tputs(tgetstr("ue", NULL), 1, ft_put_char);
}
