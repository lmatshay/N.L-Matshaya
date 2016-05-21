/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdiale <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 12:24:04 by bdiale            #+#    #+#             */
/*   Updated: 2016/05/21 17:18:58 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int	get_next_line(const int fd, char **line);

int	main()
{
	int 	fd;
	int		ext;
	//char hello[10];
	char	*line;

	fd = open("peom.txt", O_RDWR,S_IREAD);
	if (fd == -1)
	{
		write(1, "File failed to open.", 20);
		return (0);
	}
	else
		write(1, "File succesfully open.\n", 23);
//		get_next_line(fd, &line);
		get_next_line(fd, &line);
//		printf("%i", get_next_line(fd, &line));
	ext = close(fd);
	if (ext != 0)
		write(1, "File failed to close.", 22);
	else
		write(1, "\nFile succesfully closed.", 25);
	return (0);
	if (fd == -1)
		write(1,"-1",2);
	if(fd == 0)
		write(1,"0",1);
	if (fd == 1)
		write(1,"1",1);
	printf("%s", line);
}
