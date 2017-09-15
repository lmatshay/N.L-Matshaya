/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:01 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:48:03 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value(char *var)
{
	extern char	**environ;
	int			loop;
	int			sign;
	char		*tmp;

	loop = 0;
	while (environ[loop] != '\0')
	{
		tmp = get_name(environ[loop]);
		if (str_cmp(tmp, var) == 0)
		{
			sign = str_len(tmp) + 1;
			str_del(&tmp);
			return (str_dup(&(environ[loop][sign])));
		}
		str_del(&tmp);
		loop++;
	}
	return (NULL);
}
