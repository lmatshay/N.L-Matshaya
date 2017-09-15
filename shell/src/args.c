/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 14:35:57 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/11 12:23:57 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static struct s_node	*create_node(char *command)
{
	struct s_node		*next;

	next = NULL;
	if (command)
	{
		next = (struct s_node *)malloc(sizeof(struct s_node));
		if (next)
			next->data = command;
	}
	return (next);
}

void					free_nodes(struct s_node *root)
{
	struct s_node		*tmp;

	tmp = root;
	while (tmp)
	{
		free(tmp);
		tmp = tmp->next;
	}
}

struct s_node			*get_args(char *str)
{
	struct s_node		*root;
	struct s_node		*current_node;
	char				**args;
	int					count;
	int					len;

	count = 0;
	args = str_split(str, ';');
	len = ft_dstrlen(args);
	root = create_node(args[count++]);
	current_node = root;
	while (count < len)
	{
		current_node->next = create_node(args[count]);
		current_node = current_node->next;
		count++;
	}
	current_node->next = NULL;
	free(args);
	return (root);
}
