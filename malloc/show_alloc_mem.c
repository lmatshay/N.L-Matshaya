/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 13:05:08 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 17:06:10 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		tiny_memory(t_header *header, int i)
{
	ft_printf("TINY : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

int		small_memory(t_header *header, int i)
{
	ft_printf("SMALL : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

int		large_memory(t_header *header, int i)
{
	ft_printf("LARGE : %p\n", header);
	while (header && header->next)
	{
		if (!header->writable)
		{
			i += ((int)header->next) - ((int)(header) + (int)sizeof(t_header));
			ft_printf("%p - %p : %d octets\n",
				(void*)header + sizeof(t_header), header->next,
				((int)header->next) - ((int)(header) + (int)sizeof(t_header)));
		}
		header = header->next;
	}
	return (i);
}

void	show_alloc_mem(void)
{
	t_header	*header;
	int			i;

	i = 0;
	header = g_e.pstore;
	i = tiny_memory(header, i);
	header = g_e.ptrsmall;
	i = i + small_memory(header, i);
	header = g_e.ptrlarge;
	i = i + large_memory(header, i);
	ft_printf("TOTAL = %d octets\n", i);
}
