/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_in_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 10:45:11 by lmatshay          #+#    #+#             */
/*   Updated: 2016/08/26 10:45:12 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*join_strs(char *name, char *path)
{
	char	*tmp;
	char	*result;

	tmp = str_join(path, "/");
	result = str_join(tmp, name);
	str_del(&tmp);
	return (result);
}

char		*found_in_path(char *name)
{
	char		**path;
	char		*tmp;
	int			loop;
	int			found;

	path = get_path();
	loop = 0;
	found = -1;
	if (path == NULL)
		return (NULL);
	while (path[loop] != '\0')
	{
		tmp = join_strs(name, path[loop]);
		found = access(tmp, F_OK);
		if (found != -1)
		{
			del_strs(&path);
			return (tmp);
		}
		str_del(&tmp);
		loop++;
	}
	del_strs(&path);
	return (NULL);
}
