/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:41:20 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/02 12:02:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (s1)
	{
		i = 0;
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		if (n == 0 || (str1[i] == '\0' && n == 0)
			|| (str2[i] == '\0' && n == 0))
			return (0);
		while (str1[i] && str2[i] && i < n - 1)
		{
			if (str1[i] != str2[i])
				return (str1[i] - str2[i]);
			i++;
		}
		return (str1[i] - str2[i]);
	}
	return (-1);
}
