/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatshay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 12:55:30 by lmatshay          #+#    #+#             */
/*   Updated: 2017/06/18 12:55:53 by lmatshay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*chain;

	chain = (t_list *)malloc(sizeof(t_list));
	if (chain == NULL)
		return (NULL);
	chain->content = (void *)malloc(sizeof(size_t) * (content_size));
	if (chain->content == NULL)
		return (NULL);
	if (content == NULL)
	{
		chain->content = NULL;
		chain->content_size = 0;
	}
	else
	{
		chain->content = ft_memcpy(chain->content, content, content_size);
		chain->content_size = content_size;
		chain->next = NULL;
	}
	return (chain);
}
