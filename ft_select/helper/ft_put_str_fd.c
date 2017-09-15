/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 18:16:27 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/17 18:16:51 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	ft_put_str_fd(char *str, int fd)
{
	int		loop;

	loop = 0;
	while (str[loop] != '\0')
		ft_put_char_fd((int)str[loop++], fd);
}
