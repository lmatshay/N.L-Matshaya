/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 09:00:41 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/04 18:00:02 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_read_line(void)
{
	int bufsize;
	int position;
	char *buffer;
	int c;

	position = 0;
	bufsize = LINE_BUFSIZE;
	c = 0;
	buffer = malloc(sizeof(char*) * bufsize);
	if (!buffer)
	{
		ft_putstr(" allocation error\n");
		exit(EXIT_FAILURE);
	}
	ft_read_line_sub(bufsize, buffer, c, position);
	return (buffer);
}

char	*ft_read_line_sub(int bufsize, char *buffer, int c, int position)
{
	while (1) 
	{
		c = getchar();
		if (c == EOF || c == '\n') 
		{
			buffer[position] = '\0';
			return (buffer);
		} 
		else
		{
			buffer[position] = c;
			position++;
		}
		if (position >= bufsize) 
		{
			bufsize += LINE_BUFSIZE;
			buffer = ft_realloc(buffer, bufsize);
			if (!buffer)
			{
				ft_putstr("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

char **ft_line(char *line)
{
	int		position;
	int		bufsize; 
	char	**tokens;
	char	*token;

	position = 0;
	bufsize = BUFSIZE;
	tokens = malloc(sizeof(char*) * bufsize);
	if (!tokens) 
	{
		ft_putstr("allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	ft_line_sub(tokens, position, token, bufsize);
	return (tokens);
}

char	**ft_line_sub(char **tokens, int position, char *token, int bufsize)
{
	char	**tokens_backup;

	while (token != NULL) 
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize) 
		{
			bufsize += BUFSIZE;
			tokens_backup = tokens;
			tokens = ft_realloc(tokens, bufsize * sizeof(char*));
			if (!tokens) 
			{
				free(tokens_backup);
				ft_putstr("allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	token = strtok(NULL, TOK_DELIM);
	return tokens;
}

int	main(void)
{
	char *line;
	char **args;
	int ex;

	ex = 1;
	while (ex)
	{
		ft_putstr("minishell$> ");
		line = ft_read_line();
		args = ft_line(line);
		ex = execute(args);
		free(line);
		free(args);
	}
	return (EXIT_SUCCESS);
}
