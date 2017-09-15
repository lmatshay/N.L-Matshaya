/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:24 by lmatshay          #+#    #+#             */
/*   Updated: 2016/09/11 12:17:56 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int		start_shell(char *line, char *shell)
{
	char			**args;

	args = str_split(line, ' ');
	if (str_len(line) > 0 && args[0] != NULL)
	{
		if (str_cmp(args[0], "exit") == 0)
		{
			str_del(&line);
			str_del(&shell);
			del_strs(&args);
			return (0);
		}
		execute_command(args);
		str_del(&line);
		del_strs(&args);
	}
	else
	{
		str_del(&line);
		del_strs(&args);
	}
	return (1);
}

static void		helper(char *line, struct s_node *root,
						struct s_node *curr, char *shell)
{
	if (ft_index(line) >= 1)
	{
		root = get_args(line);
		curr = root;
		while (curr)
		{
			if (!start_shell(curr->data, shell))
				exit(1);
			curr = curr->next;
		}
		free_nodes(root);
		str_del(&line);
	}
	else
	{
		if (!start_shell(line, shell))
			exit(1);
	}
}

static void		minishell_main(struct s_node *root, struct s_node *curr,
								char *line, char *shell)
{
	shell = minishell();
	put_str(shell);
	line = read_line();
	if (ft_ispipe(line))
	{
		if (!execute_pipe(line))
			put_str(ANSI_COLOR_RED"error: pipe command"ANSI_COLOR_RESET);
		str_del(&line);
	}
	else
		helper(line, root, curr, shell);
	str_del(&shell);
}

int				main(void)
{
	struct sigaction	sa;
	struct s_node		*root;
	struct s_node		*curr;
	char				*line;
	char				*shell;

	root = NULL;
	curr = NULL;
	line = NULL;
	shell = NULL;
	sa.sa_handler = &handle_signal;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		put_str(ANSI_COLOR_RED"error: cannot handle SIGINT"ANSI_COLOR_RESET);
	while (1)
		minishell_main(root, curr, line, shell);
	return (0);
}
