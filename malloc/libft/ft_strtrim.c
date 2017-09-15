/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:32 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:58 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_l(const char *s)
{
	int		l;

	l = 0;
	if (s != NULL)
	{
		while (s[l + 1] != '\0')
			l++;
		while (s[l] == ' ' || s[l] == '\n' || s[l] == '\t')
			l--;
		return (l);
	}
	return (0);
}

static int		ft_get_start(const char *s)
{
	int		start;

	start = 0;
	if (s != NULL)
	{
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		return (start);
	}
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*cpy;
	int		l;
	int		i;
	int		start;

	i = 0;
	l = ft_get_l(s);
	start = ft_get_start(s);
	if (s != NULL)
	{
		cpy = (char *)malloc(l + 1);
		if (!cpy)
			return (NULL);
		while (i < (l - start))
		{
			cpy[i] = s[start + i];
			i++;
		}
		cpy[i] = s[start + i];
		cpy[i + 1] = '\0';
		return (cpy);
	}
	return (NULL);
}
