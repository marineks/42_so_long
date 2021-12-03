/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:58:10 by msanjuan          #+#    #+#             */
/*   Updated: 2021/11/26 11:35:56 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_new_string_count(char const *str, char set)
{
	size_t	i;
	size_t	count;
	char	is_not_set;
	char	next_is_set;

	i = 0;
	count = 0;
	while (str[i] == set)
		i++;
	while (str[i] != '\0')
	{
		is_not_set = str[i] != set;
		next_is_set = (str[i + 1] == set || str[i + 1] == '\0');
		if (is_not_set && next_is_set)
			count++;
		i++;
	}
	return (count);
}

static size_t	ft_letters_count(char const *str, char set, size_t i)
{
	size_t	count;

	count = 0;
	while (str[i] && str[i] != set)
	{
		count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return (tab);
}

static char	**ft_create_new_tab(char **new_tab, char const *str, char set,
size_t i)
{
	size_t	row;
	size_t	column;
	size_t	length;

	row = 0;
	column = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] != set)
		{
			length = ft_letters_count(str, set, i);
			new_tab[row] = ft_calloc(length + 1, sizeof(char));
			if (!new_tab[row])
				return (ft_free(new_tab));
			while (column < length)
				new_tab[row][column++] = str[i++];
			new_tab[row++][column] = '\0';
			column = 0;
			--i;
		}
		i++;
	}
	new_tab[row] = NULL;
	return (new_tab);
}

char	**ft_split(char const *str, char set)
{
	size_t	string_count;
	char	**new_tab;
	size_t	i;

	if (!str)
		return (NULL);
	string_count = ft_new_string_count(str, set);
	if (string_count == 0)
	{
		new_tab = ft_calloc(1, sizeof(char *));
		new_tab[0] = NULL;
		return (&new_tab[0]);
	}
	new_tab = ft_calloc(string_count + 1, sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	return (ft_create_new_tab(new_tab, str, set, i));
}
