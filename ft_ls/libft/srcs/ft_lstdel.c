/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 07:05:02 by lmatshay          #+#    #+#             */
/*   Updated: 2016/06/12 07:26:27 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst != NULL)
	{
		while (*alst != NULL)
		{
			tmp = NULL;
			if ((*alst)->next != NULL)
				tmp = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = tmp;
		}
		*alst = NULL;
	}
}
