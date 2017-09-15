/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:17:34 by lmatshay          #+#    #+#             */
/*   Updated: 2016/11/16 16:17:42 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*str_new(size_t size)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * size + 1);
	if (new != NULL)
	{
		new[size] = '\0';
		str_clr(new);
	}
	return (new);
}
