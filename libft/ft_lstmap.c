/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:23:42 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 14:51:21 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, long int (*f)(long int), void (*del)(long int))
{
	t_list	*cpy_list;
	t_list	*new;

	new = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		cpy_list = ft_lstnew((*f)(lst->number));
		if (!cpy_list)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, cpy_list);
		lst = lst->next;
	}
	return (new);
}
