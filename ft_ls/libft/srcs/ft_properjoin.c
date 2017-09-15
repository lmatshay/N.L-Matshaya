/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_properjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:10:15 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:10:22 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_properjoin(char *s1, char *s2)
{
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		ret = ft_strdup(s2);
		return (ret);
	}
	if (s2 == NULL)
	{
		ret = ft_strdup(s1);
		return (ret);
	}
	if (s1 != NULL && s2 != NULL)
	{
		ret = ft_strjoin(s1, s2);
		return (ret);
	}
	return (NULL);
}
