/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:47:43 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:47:45 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char		**get_path(void)
{
	char		*tmp;
	char		**result;

	tmp = get_value("PATH");
	if (tmp != NULL)
	{
		result = str_split(tmp, ':');
		str_del(&tmp);
		if (result != NULL)
			return (result);
	}
	return (NULL);
}
