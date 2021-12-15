/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 10:53:29 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	render(t_data *data)
{
	int 	i;
	int 	j;
	int		w;
	
	if (data->win == NULL) /* if window has been destroyed, we don't want to put the pixel ! */
		return (FAILURE);
	i = 0;
	j = 0;
	w = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->win, data->img.wall, w, i * 48);
			else if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground, w, i * 48);
			else if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, w, i * 48);
			else if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, data->img.exit, w, i * 48);
			else if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, data->img.coin, w, i * 48);
			w += 48; 
			j++;
		}
		j = 0;
		w = 0;
		i++;
	}
	return (SUCCESS);
}

	// render_background(&data->img, RED_PIXEL);
	// (t_rect){} is what is called a compound literal. 
	// 	Since C99, this is a way to initialize structures without having to manually assign each member. 
	// 	/I'm directly passing a structure by value here
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, BLUE_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});