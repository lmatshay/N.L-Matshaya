/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_managelst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 10:08:18 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/11 10:08:23 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <sys/errno.h>
#include <string.h>
#include <dirent.h>
#include "libft.h"
#include "ft_ls.h"

t_flist			*lst_new(char *name, char *fpath, t_arg **option)
{
	t_flist			*new;

	if ((new = (t_flist *)malloc(sizeof(t_flist))) == NULL)
		ft_error(1, "list creation");
	if ((new->name = ft_strdup(name)) == NULL)
		ft_error(1, name);
	if ((new->path = ft_strdup(fpath)) == NULL)
		ft_error(1, fpath);
	new->type = 0;
	new->date = NULL;
	new->year = NULL;
	new->epoc = 0;
	new->owner = NULL;
	new->group = NULL;
	new->size = NULL;
	new->link_nb = NULL;
	new->link = NULL;
	new->next = NULL;
	new->fsize_len = 0;
	new->block = 0;
	if (file_info(new->path, new->name, *option, &new) == -1)
		return (NULL);
	return (new);
}

static int		lst_2nd_t_insert(t_arg *option, t_flist **lst, t_flist *new)
{
	int				cmp;
	t_flist			*tmp;

	tmp = *lst;
	while (tmp->next != NULL && (cmp = (option->r ?
					intcmp(tmp->next->epoc, new->epoc) :
					intcmp(new->epoc, tmp->next->epoc))) <= 0)
	{
		if (cmp == 0)
		{
			while (tmp->next && (option->r ?
						ft_strcmp(tmp->next->name, new->name) :
						ft_strcmp(new->name, tmp->next->name)) > 0
						&& intcmp(tmp->next->epoc, new->epoc) == 0)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
			return (0);
		}
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
	return (0);
}

int				lst_time_insert(t_arg *option, t_flist **lst, t_flist *new)
{
	t_flist			*tmp;
	int				cmp;

	tmp = *lst;
	cmp = (option->r ? intcmp(tmp->epoc, new->epoc) :
			intcmp(new->epoc, tmp->epoc));
	if (cmp > 0 || (cmp == 0 && (option->r ? ft_strcmp(tmp->name, new->name) :
										ft_strcmp(new->name, tmp->name)) < 0))
	{
		new->next = tmp;
		*lst = new;
		return (0);
	}
	else if (tmp->next == NULL)
	{
		tmp->next = new;
		return (0);
	}
	lst_2nd_t_insert(option, lst, new);
	return (0);
}

int				lst_insert(t_arg *option, t_flist **lst, t_flist *new)
{
	t_flist			*tmp;
	int				cmp;

	tmp = *lst;
	if ((cmp = (option->r ? ft_strcmp(tmp->name, new->name) :
					ft_strcmp(new->name, tmp->name))) < 0)
	{
		new->next = tmp;
		*lst = new;
		return (0);
	}
	else if (tmp->next == NULL)
	{
		tmp->next = new;
		return (0);
	}
	while (tmp->next != NULL && (cmp = (option->r ?
					ft_strcmp(tmp->next->name, new->name) :
					ft_strcmp(new->name, tmp->next->name))) > 0)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
	return (0);
}
