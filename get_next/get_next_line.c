/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 09:24:16 by lmatshay          #+#    #+#             */
/*   Updated: 2016/05/18 17:02:11 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{
	return (0);
}

int main()
{
	int fd;
	char *read_f;
	char *stop;
	int counter;
	int	brk;
	char	*holder;

	counter = 0;
	brk = 0;
	fd = open("peom.txt", O_RDWR, S_IREAD);
	if ( fd  == -1)
	{
		write(1, "nothing happened\n",'\n');
		exit (1);
	}
	holder = (char*)malloc(sizeof(read_f));
	while (read (fd, read_f, BUFF_SIZE) && read_f[counter] != '\n')
	{
		counter = 0;
		while (read_f[counter])
		{
			if(read_f[counter] == '\n')
				{
					brk = 1;
					break;
				}
			holder[counter] = read_f[counter];
			counter++;
		}
		if (brk == 1)
			break;
	//	holder = read_f;
	//	counter++;
	}
	//printf("%i \n", counter);
   	holder[counter*BUFF_SIZE] = '\0';
   	close (fd);
   printf("%s", holder);
   return (0);
}
