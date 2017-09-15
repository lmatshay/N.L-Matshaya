/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_environ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:48:37 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:48:38 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_environ(void)
{
	extern char	**environ;
	int			loop;

	loop = 0;
	while (environ[loop] != '\0')
	{
		put_endl(environ[loop]);
		loop++;
	}
}
