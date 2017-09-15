/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:39:24 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:39:28 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_words_count(const char *s, char c)
{
	size_t		cpt;
	size_t		nb_w;

	cpt = 0;
	nb_w = 0;
	if (s != NULL)
	{
		while (s[cpt])
		{
			if (s[cpt] != c)
			{
				nb_w++;
				while (s[cpt] != c && s[cpt])
					cpt++;
			}
			cpt++;
		}
		return (nb_w + 1);
	}
	return (0);
}

char				**ft_strsplit(const char *s, char c)
{
	size_t		cpt1;
	size_t		cpt2;
	char		*tmp;
	char		**tab;
	size_t		i;

	cpt1 = 0;
	cpt2 = 0;
	i = 0;
	tab = (char **)malloc(sizeof(char*) * (ft_words_count(s, c)));
	if (ft_words_count(s, c) == 0 || tab == NULL)
		return (NULL);
	while (s[cpt1])
	{
		cpt1 = cpt2;
		while (s[cpt1] && cpt2 < ft_strlen(s) && s[cpt2] != c)
			cpt2++;
		tmp = ft_strsub(s, cpt1, cpt2 - cpt1);
		if (tmp != NULL && (cpt2 - cpt1) > 0)
			tab[i++] = tmp;
		cpt1++;
		cpt2++;
	}
	tab[i] = 0;
	return (tab);
}
