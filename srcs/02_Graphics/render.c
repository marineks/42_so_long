/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/14 13:54:34 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// void	render_background(t_img *img, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			img_pix_put(img, j++, i, color);
// 		}
// 		++i;
// 	}
// }

int	render(t_data *data)
{
	int 	i; // [y]
	int 	j;
	int		w; // [x] 

	
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


	
	// 	/* mlx_xpm_file_to_image() creates a new image in memory, using the specified xpm_data. 
	// 	It returns a void * identifier needed to manipulate this image later. */
	// data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &img_width, &img_height);

		/* Dumps the image inside a specified window at any time to display it on the screen.
		   Coordinates of the image are (0, 0) because it is covering the whole window. */
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0); 
	// }