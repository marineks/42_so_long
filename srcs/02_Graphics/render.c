/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 11:02:50 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			img_pix_put(img, j++, i, color);
		}
		++i;
	}
}

int	render(t_data *data)
{

	

	if (data->win_ptr == NULL) /* if window has been destroyed, we don't want to put the pixel ! */
		return (FAILURE);
	// else
	// {
		
		
		/* Dumps the image inside a specified window at any time to display it on the screen.
		   Coordinates of the image are (0, 0) because it is covering the whole window. */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0); 
	// }
	return (SUCCESS);
}

	// render_background(&data->img, RED_PIXEL);
	// (t_rect){} is what is called a compound literal. 
	// 	Since C99, this is a way to initialize structures without having to manually assign each member. 
	// 	/I'm directly passing a structure by value here
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, BLUE_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 500, 300, RED_PIXEL});

