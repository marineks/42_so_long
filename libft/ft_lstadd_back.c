/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 11:28:23 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/26 16:59:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*start;

	start = *alst;
	if (start == NULL)
		*alst = new;
	if (alst && *alst && new)
	{
		if (start == NULL)
			*alst = new;
		else
		{
			while (start->next != NULL)
				start = start->next;
			start->next = new;
		}
	}
}
