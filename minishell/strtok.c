/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtok.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 16:17:06 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/05 16:25:41 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *strtok(char *str, char *control) 
{
	static  char * s;
	register char * s1;

	if (str)
		s = str ;
	if (!s)
		return NULL;
	while (*s) 
	{
		if (strchr(control,*s))s++;
		else break;
	}
	s1 = s ;
	while (*s) 
	{
		if (strchr(control,*s)) 
		{
			*s++ = '\0';
			return s1 ;
		}
		s++ ;
	}
	s = NULL;
	if (*s1)return s1;
	else return NULL;
}
