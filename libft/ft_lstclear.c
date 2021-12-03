/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:21:23 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/14 17:49:41 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(long int))
{
	t_list	*current_node;
	t_list	*next_node;

	if (!lst || !*lst || !del)
		return ;
	current_node = *lst;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		if (del)
			(*del)(current_node->number);
		free(current_node);
		current_node = next_node;
	}
	*lst = NULL;
}
