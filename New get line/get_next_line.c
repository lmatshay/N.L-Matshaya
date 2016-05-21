/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 09:48:32 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/21 17:55:16 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static int counter;
	static int brk;
	char	*holder;
	int	i;
	int reader;
	char *read_f;

	counter = 0;
	brk = 0;
	i = 0;
	if (fd == -1)
		{
			return (-1);
			exit (1);
		}
	holder = (char*)malloc((BUFF_SIZE) + 1);
	read_f = (char*)malloc(BUFF_SIZE);
	*line = (char*)malloc((BUFF_SIZE) + 1);
	while ((reader = read (fd, read_f, BUFF_SIZE)) && read_f[counter] != '\n')
	{
	//	write(1,"a",1);
		while (read_f[counter] && counter >=0 && read_f[counter] != '\n')
		{
			//write(1,"a",1);
			if (read_f[counter] == '\n')
			{
				//write(1,"a",1);
				brk = 1;
				break;
			}
			holder[counter] = read_f[counter];
			counter++;
		}
		if (brk == 1)
			break;
		//return (1);
	}
	holder[counter*BUFF_SIZE] = '\0';
	*line = holder;
	printf("%s", holder);
	return (1);
}
	
