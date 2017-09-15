/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:06:06 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:06:12 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	while (lst != NULL && (*f))
	{
		if (new == NULL)
		{
			new = f(lst);
			tmp = new;
		}
		else
		{
			tmp->next = f(lst);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (new);
}
