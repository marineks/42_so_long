/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 15:21:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	render(t_data *data)
{
	int 	i;
	int 	j;
	int		w;
	
	if (data->win == NULL)
		return (FAILURE);
	i = 0;
	j = 0;
	width = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin, 
					width, i * IMG_SIZE);
			width += IMG_SIZE; 
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (SUCCESS);
}
