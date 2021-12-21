/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:16:38 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 12:01:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	init_window_bonus(t_data *data)
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

void	init_images_bonus(t_data *data)
{
	data->img.wall = mlx_xpm_file_to_image(data->mlx, W_RAND, &data->img.width, 
		&data->img.height);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, GROUND, 
		&data->img.width, &data->img.height);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, LOCKED, &data->img.width, 
		&data->img.height);
	data->img.exit_u = mlx_xpm_file_to_image(data->mlx, EXIT, &data->img.width, 
		&data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, PLAYER, 
		&data->img.width, &data->img.height);
	if (data->map.count_f)
		data->img.foe = mlx_xpm_file_to_image(data->mlx, FOE, 
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
	data->img.corner_tl2 = mlx_xpm_file_to_image(data->mlx, C_TL2, 
		&data->img.width, &data->img.height);
	data->img.corner_tl3 = mlx_xpm_file_to_image(data->mlx, C_TL3, 
		&data->img.width, &data->img.height);
	data->img.corner_tr = mlx_xpm_file_to_image(data->mlx, C_TR, 
		&data->img.width, &data->img.height);
	data->img.corner_tr2 = mlx_xpm_file_to_image(data->mlx, C_TR2, 
		&data->img.width, &data->img.height);
	data->img.corner_tr3 = mlx_xpm_file_to_image(data->mlx, C_TR3, 
		&data->img.width, &data->img.height);
	data->img.corner_bl = mlx_xpm_file_to_image(data->mlx, C_BL, 
		&data->img.width, &data->img.height);
	data->img.corner_bl2 = mlx_xpm_file_to_image(data->mlx, C_BL2, 
		&data->img.width, &data->img.height);
	data->img.corner_bl3 = mlx_xpm_file_to_image(data->mlx, C_BL3, 
		&data->img.width, &data->img.height);
	data->img.corner_br = mlx_xpm_file_to_image(data->mlx, C_BR, 
		&data->img.width, &data->img.height);
	data->img.corner_br2 = mlx_xpm_file_to_image(data->mlx, C_BR2, 
		&data->img.width, &data->img.height);
	data->img.corner_br3 = mlx_xpm_file_to_image(data->mlx, C_BR3, 
		&data->img.width, &data->img.height);
}

void	loop_images_bonus(t_data data)
{
	mlx_loop_hook(data.mlx, &render_bonus, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress_bonus, &data);
	mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrealease_bonus, 
		&data);
	mlx_loop(data.mlx);
}

void	destroy_images_bonus(t_data data)
{
	mlx_destroy_image(data.mlx, data.img.wall);
	mlx_destroy_image(data.mlx, data.img.ground);
	mlx_destroy_image(data.mlx, data.img.player);
	if (data.map.count_f)
		mlx_destroy_image(data.mlx, data.img.foe);
	mlx_destroy_image(data.mlx, data.img.exit_l);
	mlx_destroy_image(data.mlx, data.img.exit_u);
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
	mlx_destroy_image(data.mlx, data.img.corner_bl2);
	mlx_destroy_image(data.mlx, data.img.corner_bl3);
	mlx_destroy_image(data.mlx, data.img.corner_br);
	mlx_destroy_image(data.mlx, data.img.corner_br2);
	mlx_destroy_image(data.mlx, data.img.corner_br3);
	mlx_destroy_image(data.mlx, data.img.corner_tl);
	mlx_destroy_image(data.mlx, data.img.corner_tl2);
	mlx_destroy_image(data.mlx, data.img.corner_tl3);
	mlx_destroy_image(data.mlx, data.img.corner_tr);
	mlx_destroy_image(data.mlx, data.img.corner_tr2);
	mlx_destroy_image(data.mlx, data.img.corner_tr3);
	mlx_destroy_display(data.mlx);
}