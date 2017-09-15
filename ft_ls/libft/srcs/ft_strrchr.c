/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:25:09 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:25:14 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char*)s;
	while (*tmp != '\0')
		tmp++;
	while ((tmp != s) && (*tmp != c))
		tmp--;
	if ((tmp == s) && (*s != c))
		return (NULL);
	return (tmp);
}
