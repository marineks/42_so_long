/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:52:46 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 09:00:50 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include "../../includes/get_next_line.h"

int	checkChars_bonus(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		while(data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.count_p++;
				data->p_i = i;
				data->p_j = j;
			}
			else if (data->map.map[i][j] == 'F')
			{
				data->map.count_f++;
				data->f_i = i;
				data->f_j = j;
			}
			else if (data->map.map[i][j] == 'E')
				data->map.count_e++;
			else if (data->map.map[i][j] == 'C')
				data->map.count_c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!data->map.count_c || !data->map.count_e || !data->map.count_p)
		return (FAILURE);
	else
		return (SUCCESS);
}

int checkTopBot_bonus(int row, char **map)
{
	int i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	checkEdges_bonus(int line_count, char **map)
{
	int i;

	i = 1;
	if (checkTopBot_bonus(0, map) == FAILURE 
		|| checkTopBot_bonus(line_count, map) == FAILURE)
		return (FAILURE);
	while (i < line_count) // vérifier cotés
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[0]) - 2] != '1') 
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	checkRectangle_bonus(t_data *data)
{
	int i;
	size_t j;

	i = 0;
	j = 0;
	data->map.line_len = ft_strlen(data->map.map[i]) - 1;
	while (data->map.map[i])
	{		
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
			j++;
		if (j != data->map.line_len)
			return (FAILURE);
		j = 0;
		i++;
	}
	return (SUCCESS);
}

int	checkMap_bonus(t_data *data)
{
	int i;
	size_t j;
	
	i = 0;
	j = 0;
	while (data->map.map[i])
	{	
		while (j < ft_strlen(data->map.map[i]) - 1)
		{
			if (ft_strchr("01CEPF", data->map.map[i][j]) == NULL)
				error_msg_bonus(ERROTHER, data);
			j++;
		}
		j = 0;
		i++;
	}
	if (checkChars_bonus(data) == FAILURE)
		error_msg_bonus(ERRCHARS, data);
	if (data->map.count_p > 1 || data->map.count_f > 1)
		error_msg_bonus(ERRPLAYERB, data);
	if (checkRectangle_bonus(data) == FAILURE)
		error_msg_bonus(ERRREC, data);
	if (checkEdges_bonus(data->map.line_count - 1, data->map.map) == FAILURE)
		error_msg_bonus(ERREDGES, data);
	return (SUCCESS);
}