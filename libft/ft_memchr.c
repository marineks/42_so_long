/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:48:09 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/30 11:54:07 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	occurence;
	size_t			i;

	i = 0;
	string = (unsigned char *)s;
	occurence = (unsigned char)c;
	if (occurence == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if (string[i] == occurence)
			return (string + i);
		i++;
	}
	return (NULL);
}
