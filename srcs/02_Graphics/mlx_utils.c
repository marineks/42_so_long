/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:16:38 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 15:19:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (ERROR);	
	data->win = mlx_new_window(data->mlx, data->win_width, 
		data->win_height, TITRE);
	if (data->win == NULL)
	{
		free(data->win);
		return (ERROR);
	}
	return (SUCCESS);
}

void	init_images(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->img.width, 
		&data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND, 
		&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->img.width, 
		&data->img.height);
	data->img.coin = mlx_xpm_file_to_image(data->mlx, COIN, &data->img.width, 
		&data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, 
		&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrealease, 
		&data);
	mlx_hook(data.win, Expose, ExposureMask, &handle_resize, &data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit);
	mlx_destroy_image(data.mlx, data.img.coin);
	mlx_destroy_display(data.mlx);
}