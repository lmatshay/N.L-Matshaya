/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 17:18:28 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 17:18:33 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <stdbool.h>

# define TINY 4096
# define SMALL 16384

typedef struct			s_env
{
	void *pstore;
	void *ptrsmall;
	void *ptrlarge;
	void *tmp;
}						t_env;

t_env					g_e;

typedef struct			s_header
{
	void	*next;
	void	*prev;
	size_t	size;
	bool	writable;
}						t_header;

/*
**concat.c
*/

void					ft_concat_large(void *data);
void					ft_concattiny(int memory, int i, t_header *header);
void					ft_concat2(int memory, int i, t_header *header);
void					*ft_concat(size_t i);
/*
**show_alloc_mem.c
*/

int						showalloc_mem_tiny(t_header *header, int i);
int						showalloc_mem_small(t_header *header, int i);
int						showalloc_mem_large(t_header *header, int i);
void					show_alloc_mem(void);
/*
**free.c
*/

void					ft_defrag(void *pointer);
void					merge_header(t_header *current, t_header *after);
void					freeforlarge(t_header *data);
void					free(void *pointer);
/*
**create.c
*/

void					*ft_creat(size_t i, int type, void *prevaddr);
void					*ft_creatlarge(size_t i);
void					print_header(t_header *header);
bool					findinheader(void *addr);
/*
**malloc.h
*/

void					*realloc(void *ptr, size_t size);
void					*ft_tiny(size_t i);
void					*ft_small(size_t i);
void					*malloc(size_t i);
#endif
