/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:01:06 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/25 11:58:20 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_source;
	size_t			i;

	i = 0;
	ptr_dest = (unsigned char *)dst;
	ptr_source = (unsigned char *)src;
	if (ptr_dest == NULL && ptr_source == NULL)
		return (NULL);
	while (i < n)
	{
		ptr_dest[i] = ptr_source[i];
		i++;
	}
	return (dst);
}
