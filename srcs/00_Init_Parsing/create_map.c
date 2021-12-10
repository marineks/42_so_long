/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:42:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/10 15:51:03 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"
#include <stdio.h>

void ft_free(char **tab)
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
	return ;
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
	

void	createMap(char *path, t_data *data)
{
	char *line;
	int row;
	int i;
	size_t column;

	data->map.path = path;
	// Malloc le double tableau
	data->map.map = ft_calloc(data->map.line_count + 1, sizeof(char *));
	if (!(data->map.map))
		return ;

	// Récupérer la taille de chaque ligne et malloc lesdites lignes
	i = row = column = 0;
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		while ((line = get_next_line(data->map.fd)) != NULL)
		{
			data->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
			if (!data->map.map[row])
				return (ft_free(data->map.map));
			while (line[i] != '\0')
				data->map.map[row][column++] = line[i++];
			data->map.map[row++][column] = '\0';
			column = 0;
			i = 0;
			free(line);
		}
		data->map.map[row] = NULL;
		close(data->map.fd);
	}
}
	
	