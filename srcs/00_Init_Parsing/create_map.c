/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:42:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 15:00:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"
#include <stdio.h>

char **ft_free(char **tab)
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
	return (NULL);
}

// Récupérer le nombre de lignes dans le fichier .ber
int	retrieveLineNumber(char *path)
{
	int		fd;
    char    *line;
	int line_count;
	
	line_count = 0;
	fd = open(path, O_RDONLY);

	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			line_count++;
			free(line);
		}
		close(fd);
	}
	return (line_count);
}
	

char**	createMap(char *path, int line_count)
{
	char **map;
	char *line;
	int row;
	int i;
	int fd;
	size_t column;

	// Malloc le double tableau
	map = ft_calloc(line_count + 1, sizeof(char *));
	if (!map)
		return (NULL);

	// Récupérer la taille de chaque ligne et malloc lesdites lignes
	i = row = column = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		while ((line = get_next_line(fd)) != NULL)
		{
			map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
			if (!map[row])
				return (ft_free(map));
			while (line[i] != '\0')
				map[row][column++] = line[i++];
			map[row++][column] = '\0';
			column = 0;
			i = 0;
			free(line);
		}
		map[row] = NULL;
		close(fd);
	}
	return (map);
}
	
	