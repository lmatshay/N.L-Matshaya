/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 16:52:36 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/12 18:01:52 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *first;
	char *second;
	int i;
	int size;

	i = 0;
	first = (char*)malloc(sizeof(*s1 + *s2));
	first = (char*)s1;
	size = ft_strlen(first);
	second = (char*)s2;
	while (first[size])
	{
		first[i] = first[i] + second[i];
	   	i++;
	}
	first[i] = '\0';
	return (first);	
}

int main()
{
	char *a;
	char *b;
	char *c;

	a = "please";
	b = "join";
	c = ft_strjoin(a, b);
	printf("%s", c);
	return (0);
}

