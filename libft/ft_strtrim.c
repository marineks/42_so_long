/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:44:36 by msanjuan          #+#    #+#             */
/*   Updated: 2021/06/26 12:18:33 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ischarset_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			return (i);
		i++;
		j = 0;
	}
	return (i);
}

static size_t	ft_ischarset_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (i > 0)
	{
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			return (i);
		j = 0;
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s1;
	char	*tmp;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!set || !s1)
		return (NULL);
	start = ft_ischarset_start(s1, set);
	end = ft_ischarset_end(s1, set);
	if (ft_strlen(s1) == 0 || (start == ft_strlen(s1) && end == 0))
	{
		tmp = (char *)malloc(sizeof(char) * 1);
		tmp[0] = 0;
		return (tmp);
	}
	trimmed_s1 = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!trimmed_s1)
		return (NULL);
	i = 0;
	while (start <= end)
		trimmed_s1[i++] = s1[start++];
	trimmed_s1[i] = '\0';
	return (trimmed_s1);
}
