/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_permissions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmacheke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 10:08:50 by mmacheke          #+#    #+#             */
/*   Updated: 2016/06/11 10:08:55 by mmacheke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"
#include "libft.h"

static char		get_uid(struct stat buff_stat)
{
	char	ret;

	ret = (buff_stat.st_mode & S_IXUSR) ? 'x' : '-';
	if (ret == 'x' && (buff_stat.st_mode & S_ISUID))
		ret = 's';
	else if (ret == '-' && (buff_stat.st_mode & S_ISUID))
		ret = 'S';
	return (ret);
}

static char		get_gid(struct stat buff_stat)
{
	char	ret;

	ret = (buff_stat.st_mode & S_IXGRP) ? 'x' : '-';
	if (ret == 'x' && (buff_stat.st_mode & S_ISGID))
		ret = 's';
	else if (ret == '-' && (buff_stat.st_mode & S_ISGID))
		ret = 'S';
	return (ret);
}

static char		sticky_bit(struct stat buff_stat)
{
	char	ret;

	ret = (buff_stat.st_mode & S_IXOTH) ? 'x' : '-';
	if (ret == 'x' && (buff_stat.st_mode & S_ISVTX))
		ret = 't';
	else if (ret == '-' && (buff_stat.st_mode & S_ISVTX))
		ret = 'T';
	return (ret);
}

int				file_rights(t_flist **lst, struct stat buff_stat)
{
	(*lst)->rights[0] = (*lst)->type;
	(*lst)->rights[1] = (buff_stat.st_mode & S_IRUSR) ? 'r' : '-';
	(*lst)->rights[2] = (buff_stat.st_mode & S_IWUSR) ? 'w' : '-';
	(*lst)->rights[3] = get_uid(buff_stat);
	(*lst)->rights[4] = (buff_stat.st_mode & S_IRGRP) ? 'r' : '-';
	(*lst)->rights[5] = (buff_stat.st_mode & S_IWGRP) ? 'w' : '-';
	(*lst)->rights[6] = get_gid(buff_stat);
	(*lst)->rights[7] = (buff_stat.st_mode & S_IROTH) ? 'r' : '-';
	(*lst)->rights[8] = (buff_stat.st_mode & S_IWOTH) ? 'w' : '-';
	(*lst)->rights[9] = sticky_bit(buff_stat);
	(*lst)->rights[10] = ' ';
	(*lst)->rights[11] = ' ';
	(*lst)->rights[12] = '\0';
	return (0);
}

char			file_type(struct stat buff_stat)
{
	char				type;

	if (S_ISBLK(buff_stat.st_mode))
		type = 'b';
	else if (S_ISREG(buff_stat.st_mode))
		type = '-';
	else if (S_ISCHR(buff_stat.st_mode))
		type = 'c';
	else if (S_ISDIR(buff_stat.st_mode))
		type = 'd';
	else if (S_ISFIFO(buff_stat.st_mode))
		type = 'p';
	else if (S_ISLNK(buff_stat.st_mode))
		type = 'l';
	else if (S_ISSOCK(buff_stat.st_mode))
		type = 's';
	else
		type = '?';
	return (type);
}
