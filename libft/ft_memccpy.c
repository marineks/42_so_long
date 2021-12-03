/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:41:29 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/24 19:41:00 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_source;
	unsigned char	occurence;
	size_t			i;

	ptr_dest = (unsigned char *)dst;
	ptr_source = (unsigned char *)src;
	occurence = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_source[i];
		if (ptr_dest[i] == occurence)
		{
			return (dst + 1 + i);
		}
		i++;
	}
	return (NULL);
}
