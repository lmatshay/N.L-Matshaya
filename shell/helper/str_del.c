/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:42:29 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:42:30 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	str_del(char **str)
{
	str_clr(str[0]);
	free(str[0]);
	str[0] = NULL;
}
