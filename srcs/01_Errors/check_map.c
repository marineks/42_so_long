/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:52:46 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 19:14:48 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

int	checkChars(char **map)
{
	int i;
	int j;
	int count_p;
	int count_e;
	int count_c;

	i = 0;
	j = 0;
	count_c = count_e = count_p = 0;
	while (map[i])
	{
		while(map[i][j])
		{
			if (map[i][j] == 'P')
				count_p++;
			else if (map[i][j] == 'E')
				count_e++;
			else if (map[i][j] == 'C')
				count_c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!count_c || !count_e || !count_p)
		return (FAILURE);
	else
		return (SUCCESS);
}

int	checkEdges(int line_count, char **map)
{
	size_t len;
	int i;

	i = 0;
	len = ft_strlen(map[0]);
	// vérifier premiere ligne
	while (map[0][i] != '\0')
	{
		if (map[0][i] != '1')
			return (FAILURE);
		i++;
	}
	i = 0;
	// vérifier derniere ligne
	while (map[line_count - 1][i] != '\0')
	{
		if (map[line_count][i] != '1')
			return (FAILURE);
		i++;
	}
	// vérifier cotés
	i = 1;
	while (i < line_count - 2)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	checkRectangle(char **map)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != '\n' || map[i][j])
		{
			
			// if (i == '\n')
			// 	j--;
			j++;
		}
		// printf("j : %zu | ft_strlen(map[i]) : %zu\n", j, ft_strlen(map[i]));
		if (j != ft_strlen(map[i]))
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	checkMap(int line_count, char **map)
{
	int i;
	size_t j;
	size_t len;
	
	i = 0;
	j = 0;
	len = ft_strlen(map[i]);
	while (map[i])
	{	
		while (j < len - 1)
		{
			/* Vérifier qu'il n'y a pas d'autres chars que les 0, 1, E, C, P */
			/* Vérifier que les chars 0, 1, E, C, P sont presents */
			printf("Char : %c\n", map[i][j]);
			if (ft_strchr("01CEP", map[i][j]) == NULL)
			{
				ft_free(map);
				error_msg("At least one character of the map is not valid.\n");
			}
			else if (checkChars(map) == FAILURE)
			{
				ft_free(map);
				error_msg("One of the characters \"0, 1, P, C, E\" is missing.\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
	/* Vérifier que c'est bien un carré ou rectangle. */
	if (checkRectangle(map) == FAILURE)
	{
		ft_free(map);
		error_msg("The map is not a rectangle.\n");
	}
	/* Vérifier que les bordures soient bien des 1 */
	if (checkEdges(line_count, map) == FAILURE)
	{
		ft_free(map);
		error_msg("The edges of the map are invalid (must be walls -1-)\n");
	}
	return (SUCCESS);
}