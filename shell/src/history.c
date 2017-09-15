/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 11:02:39 by lmatshay          #+#    #+#             */
/*   Updated: 2016/11/14 11:02:47 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../minishell.h"

struct	node	*create_node(char *command)
{
	struct node	*next;

	if (command)
	{
		next = (struct node *)malloc(sizeof(struct node));
		if (next)
			next->data = command;
	}
	return (next);
}

int				add_node(struct node *current_node, char *command)
{
	struct node	*next;

	if (current_node)
	{
		next = create_node(command);
		if (next)
		{
			current_node->next = next;
			return (1);
		}
	}
	return (0);
}

void			free_nodes(struct node *root)
{
	struct node	*tmp;

	tmp = root;
	while (tmp)
	{
		free(tmp->data);
		free(tmp);
		tmp = tmp->next;
	}
}

void			display_node(struct node *root, int num)
{
	struct node	*tmp;
	int			count;

	tmp = root;
	count = 0;
	while (tmp && count < num)
	{
		tmp = tmp->next;
		count++;
	}
	printf("%s\n", tmp->data);
}

int				main(int argc, char **argv)
{
	struct node	*root;
	struct node	*current_node;
	int			count;

	count = 0;
	if (argc > 1)
	{
		root = create_node(*++argv);
		current_node = root;
		while (count < (argc - 1))
		{
			current_node->next = create_node(*++argv);
			current_node = current_node->next;
			count++;
		}
		current_node->next = NULL;
		display_node(root, listlen(root) - 1);
	}
	return (0);
}
