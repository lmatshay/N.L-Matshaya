/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:41:14 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:41:15 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*read_line(void)
{
	char	*line;
	char	c;
	int		loop;
	int		size;

	loop = 0;
	size = 1024;
	line = str_new(size);
	if (line == NULL)
		return (NULL);
	while (1)
	{
		c = get_char();
		if (c == '\n' || c == '\0')
		{
			line[loop] = '\0';
			return (line);
		}
		line[loop++] = c;
		if (loop >= size - 1)
		{
			size *= 2;
			resize_str(&line, size);
		}
	}
}
