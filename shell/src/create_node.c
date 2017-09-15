/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:02:39 by lmatshay          #+#    #+#             */
/*   Updated: 2016/11/17 12:11:44 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_signal(int signal)
{
	char	*sh;

	sh = minishell();
	if (signal == SIGINT)
	{
		put_chr('\n');
		put_str(sh);
	}
	str_del(&sh);
}

int		listlen(struct node *root)
{
	struct node	*tmp;
	int			len;

	tmp = root;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
