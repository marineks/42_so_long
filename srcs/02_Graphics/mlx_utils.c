/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:16:38 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/17 14:46:12 by msanjuan         ###   ########.fr       */
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
	// data->img.wall = mlx_xpm_file_to_image(data->mlx, WALL, &data->img.width, 
	// 	&data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND, 
		&data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT, &data->img.width, 
		&data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, 
		&data->img.width, &data->img.height);
	data->img.coin1 = mlx_xpm_file_to_image(data->mlx, COIN1, 
		&data->img.width, &data->img.height);
	data->img.coin2 = mlx_xpm_file_to_image(data->mlx, COIN2, 
		&data->img.width, &data->img.height);
	data->img.coin3 = mlx_xpm_file_to_image(data->mlx, COIN3, 
		&data->img.width, &data->img.height);
	data->img.coin4 = mlx_xpm_file_to_image(data->mlx, COIN4, 
		&data->img.width, &data->img.height);
	data->img.coin5 = mlx_xpm_file_to_image(data->mlx, COIN5, 
		&data->img.width, &data->img.height);
		data->img.wall_t = mlx_xpm_file_to_image(data->mlx, W_TOP, 
		&data->img.width, &data->img.height);
	data->img.wall_b = mlx_xpm_file_to_image(data->mlx, W_BOT, 
		&data->img.width, &data->img.height);
	data->img.wall_l = mlx_xpm_file_to_image(data->mlx, W_LEFT, 
		&data->img.width, &data->img.height);
	data->img.wall_r = mlx_xpm_file_to_image(data->mlx, W_RIGHT, 
		&data->img.width, &data->img.height);
	data->img.corner_tl = mlx_xpm_file_to_image(data->mlx, C_TL, 
		&data->img.width, &data->img.height);
		data->img.corner_tr = mlx_xpm_file_to_image(data->mlx, C_TR, 
		&data->img.width, &data->img.height);
	data->img.corner_bl = mlx_xpm_file_to_image(data->mlx, C_BL, 
		&data->img.width, &data->img.height);
	data->img.corner_br = mlx_xpm_file_to_image(data->mlx, C_BR, 
		&data->img.width, &data->img.height);
}

void	loop_images(t_data data)
{
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrealease, 
		&data);
	// mlx_hook(data.win, Expose, ExposureMask, &handle_resize, &data);
	mlx_loop(data.mlx);
}

void	destroy_images(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	mlx_destroy_image(data.mlx, data.img.exit);
	mlx_destroy_image(data.mlx, data.img.coin1);
	mlx_destroy_image(data.mlx, data.img.coin2);
	mlx_destroy_image(data.mlx, data.img.coin3);
	mlx_destroy_image(data.mlx, data.img.coin4);
	mlx_destroy_image(data.mlx, data.img.coin5);
	mlx_destroy_image(data.mlx, data.img.wall_t);
	mlx_destroy_image(data.mlx, data.img.wall_b);
	mlx_destroy_image(data.mlx, data.img.wall_l);
	mlx_destroy_image(data.mlx, data.img.wall_r);
	mlx_destroy_image(data.mlx, data.img.corner_bl);
	mlx_destroy_image(data.mlx, data.img.corner_br);
	mlx_destroy_image(data.mlx, data.img.corner_tl);
	mlx_destroy_image(data.mlx, data.img.corner_tr);
	mlx_destroy_display(data.mlx);
}