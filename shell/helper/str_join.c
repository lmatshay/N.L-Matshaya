/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:43:07 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:43:08 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*str_join(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = str_len(s1);
	len_s2 = str_len(s2);
	new = str_new(len_s1 + len_s2);
	if (new != NULL)
	{
		str_cpy(new, s1);
		str_cpy(&(new[len_s1]), s2);
	}
	return (new);
}
