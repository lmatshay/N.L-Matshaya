/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 08:11:24 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/12 09:22:48 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strstr(const char *big, const char *little)
{
	int i;
	int	sl_big;
	int sl_little;
	char s_v1[50];

	i = 0;
	sl_big = ft_strlen(big);
	sl_little = ft_strlen(little);
	if (sl_little > 0)
	{
		while (little[i])
		{
			if (big[i] == little[i])
			{
				s_v1[i] = big[i];
				i++;
			}
		}
		s_v1[i] = '\0';
		return (s_v1);
	}
	else if (sl_little == 0)
		return (big);
	else
		return (NULL);
}


}

int	main()
{
	char a[] = "Im Luthando";
	char b[] = "Luthando";
	char c = *ft_strstr(a, b);

	printf("%c", c);
	return (0);
}
