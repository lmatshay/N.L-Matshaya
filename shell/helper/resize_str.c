/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:41:24 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:41:26 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	resize_str(char **str, size_t new_size)
{
	char	*tmp;

	tmp = str[0];
	str[0] = str_new(new_size);
	if (str[0] != NULL)
	{
		str_cpy(str[0], tmp);
		str_del(&tmp);
	}
}
