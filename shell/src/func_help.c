/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:46:39 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:57:02 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	func_help(void)
{
	put_str(ANSI_COLOR_GREEN);
	put_str("* Type a command followed by a few");
	put_endl(" argmunents then press enter to run the command");
	put_str("* For specific information on a command, type");
	put_endl(" 'man' followed by the command's name");
	put_str(ANSI_COLOR_RESET);
}
