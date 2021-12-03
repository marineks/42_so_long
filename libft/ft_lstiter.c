/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:09:30 by msanjuan          #+#    #+#             */
/*   Updated: 2021/10/14 17:49:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(long int))
{
	if (lst && f)
	{
		while (lst->next != NULL)
		{
			(*f)(lst->number);
			lst = lst->next;
		}
		(*f)(lst->number);
	}
}
