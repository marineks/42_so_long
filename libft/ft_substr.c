/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:55:03 by msanjuan          #+#    #+#             */
/*   Updated: 2021/08/07 13:21:55 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	size_t	i;
	size_t	size;
	size_t	index;

	if (*s == '\0')
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (size > len)
		size = len;
	new_string = (char *)malloc((size + 1) * sizeof(char));
	if (!new_string)
		return (NULL);
	i = (size_t)start;
	index = 0;
	while (index < size)
		new_string[index++] = s[i++];
	new_string[index] = '\0';
	return (new_string);
}
