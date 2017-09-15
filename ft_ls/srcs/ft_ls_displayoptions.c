/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_displayoptions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 10:07:12 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/11 10:07:17 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include "libft.h"
#include "ft_ls.h"

static int		format_majmin(t_flist **lst, t_arg **option)
{
	char		len[(*option)->min_len + 1];
	char		*tmp;
	int			size;
	int			i;
	int			j;

	i = -1;
	j = -1;
	len[(*option)->min_len] = '\0';
	size = ((*option)->min_len - ft_strlen((*lst)->minor));
	while (++i < size)
		len[i] = ' ';
	while ((*lst)->minor[++j])
		len[i++] = (*lst)->minor[j];
	if ((tmp = ft_strjoin((*lst)->major, len)) == NULL)
		ft_error(3, (*lst)->major);
	if (((*lst)->size = ft_strdup(tmp)) == NULL)
		ft_error(3, tmp);
	(*lst)->fsize_len = ft_strlen((*lst)->size);
	if (((*option)->a == 1 || ((*option)->a == 0 && (*lst)->name[0] != '.'))
			&& (*lst)->fsize_len > (*option)->size_len)
		(*option)->size_len = (*lst)->fsize_len;
	ft_strdel(&tmp);
	return (0);
}

static int		display_size_date(t_flist **lst, t_arg *opt)
{
	put_space((*lst)->size, opt->size_len);
	ft_putstr((*lst)->size);
	ft_putchar(' ');
	ft_putstr((*lst)->date);
	ft_putstr((*lst)->year);
	ft_putchar(' ');
	return (0);
}

int				long_display(t_flist **lst, t_arg *opt)
{
	ft_putstr((*lst)->rights);
	put_space((*lst)->link_nb, opt->lk_len);
	ft_putstr((*lst)->link_nb);
	ft_putchar(' ');
	if (opt->g == 0)
	{
		ft_putstr((*lst)->owner);
		put_space((*lst)->owner, (opt->own_len + 2));
	}
	if (opt->o == 0)
	{
		ft_putstr((*lst)->group);
		put_space((*lst)->group, (opt->gr_len + 2));
	}
	if (opt->o == 1 && opt->g == 1)
		ft_putstr("  ");
	if ((opt->a == 1 || (opt->a == 0 && (*lst)->name[0] != '.'))
			&& ((*lst)->type == 'b' || (*lst)->type == 'c'))
		format_majmin(lst, &opt);
	display_size_date(lst, opt);
	return (0);
}

int				display_total(t_arg **opt, int i)
{
	if (i > 0 && ((*opt)->l == 1 || (*opt)->o == 1
				|| (*opt)->g == 1))
	{
		ft_putstr("total ");
		ft_putnbrendl((*opt)->tot_blocks);
	}
	(*opt)->tot_blocks = 0;
	return (0);
}
