/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 13:04:35 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 17:09:42 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
	void		*teen;

	if (size == 0 || !ptr)
		return (ptr);
	if (!findinheader(ptr) || !(teen = malloc(size)))
		return (NULL);
	ft_memcpy(teen, ptr, size);
	free(ptr);
	return (teen);
}

void		*ft_tiny(size_t i)
{
	void *data;

	data = NULL;
	g_e.tmp = g_e.pstore;
	if (g_e.pstore)
	{
		data = ft_list(i);
		g_e.pstore = g_e.tmp;
		return (data);
	}
	else
	{
		data = ft_creat(i, TINY, NULL);
		g_e.pstore = g_e.tmp;
		return (data);
	}
}

void		*ft_small(size_t i)
{
	void *data;

	data = NULL;
	g_e.tmp = g_e.ptrsmall;
	if (g_e.ptrsmall)
	{
		data = ft_list(i);
		g_e.ptrsmall = g_e.tmp;
		return (data);
	}
	else
	{
		data = ft_creat(i, SMALL, NULL);
		g_e.ptrsmall = g_e.tmp;
		return (data);
	}
}

void		*malloc(size_t i)
{
	void *data;

	data = NULL;
	if (i <= TINY)
		return (ft_tiny(i));
	else if (i <= SMALL)
		return (ft_small(i));
	else
	{
		if (g_e.ptrlarge)
		{
			data = ft_creatlarge(i);
			if (data)
				ft_merge_large(data);
			return (data);
		}
		else
		{
			data = ft_creatlarge(i);
			if (data)
				g_e.ptrlarge = data - sizeof(t_header);
			return (data);
		}
	}
}
