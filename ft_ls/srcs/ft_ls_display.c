/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 10:06:58 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/11 10:07:04 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int				display_dirname(t_arg *option, char *str)
{
	if (option->arg_nb > 1 || option->recu == 1)
	{
		ft_putchar('\n');
		ft_putstr(str);
		ft_putendl(":");
	}
	return (0);
}

static int		second_display(t_arg *option, t_flist *tmp)
{
	if (option->a == 1 && tmp->type == 'd')
	{
		if (option->arg_nb > 1)
			display_dirname(option, tmp->name);
		if (recu_dir(option, tmp->path, tmp->name) == -1)
			return (-1);
	}
	else if (tmp->type == 'd' && ft_strcmp(tmp->name, ".")
			&& option->a != 1 && ft_strcmp(tmp->name, ".."))
	{
		if (option->arg_nb > 1)
			display_dirname(option, tmp->name);
		if (recu_dir(option, tmp->path, tmp->name) == -1)
			return (-1);
	}
	return (0);
}

int				first_display(t_flist **lst, t_arg *option)
{
	t_flist		*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->type != 'd')
			ls_display(option, &tmp);
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp != NULL)
	{
		option->tot_blocks = 0;
		second_display(option, tmp);
		tmp = tmp->next;
	}
	return (0);
}

int				put_space(char *str, int len)
{
	int			i;

	i = ft_strlen(str);
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (0);
}

int				ls_display(t_arg *option, t_flist **lst)
{
	if (option->l == 1 || option->o == 1 || option->g == 1)
		long_display(lst, option);
	ft_putstr((*lst)->name);
	if (option->p && (*lst)->type == 'd')
		ft_putchar('/');
	if ((option->l == 1 || option->o == 1 || option->g == 1)
			&& (*lst)->type == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr((*lst)->link);
	}
	ft_putendl("");
	return (0);
}
