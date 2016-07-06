/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 14:34:52 by lmatshay          #+#    #+#             */
/*   Updated: 2016/07/06 15:45:22 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

char *builtin_str[] = {
	"cd", 
	"help",
   	"exit",
	"setenv",
	"unsetenv",
};

int	(*builtin_func[]) (char **) = {
	&ft_cd, 
	&ft_help, 
	&ft_exit,
	&ft_setenv,
	&ft_unsetenv,
};

int	num_builtins() {
	return sizeof(builtin_str) / sizeof(char*);
}

#endif
