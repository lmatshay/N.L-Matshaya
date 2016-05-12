/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 10:16:36 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/12 10:46:22 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char	*first;
	char	*second;

	first = s1;
	second = (char *)s2;
	while (*first != '\0')
	{
		first++;
	}
	while (*second != '\0')
	{
		*first = *second;
		first++;
		second++;
	}
	*second = '\0';
	return (s1);
}

int main ()
{
	char src[50], dest[50];

	ft_strcpy(src,  "Luthando");
	ft_strcpy(dest, "hi my name is");

	ft_strcat(dest, src);

	printf(/*Final destination string : |*/"%s", dest);

	return(0);
}
