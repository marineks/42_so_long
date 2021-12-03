/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:12:08 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/25 11:56:56 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*first_string;
	unsigned char	*second_string;

	i = 0;
	first_string = (unsigned char *)s1;
	second_string = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1)
	{
		if (first_string[i] != second_string[i])
		{
			return (first_string[i] - second_string[i]);
		}
		i++;
	}
	return (first_string[i] - second_string[i]);
}
