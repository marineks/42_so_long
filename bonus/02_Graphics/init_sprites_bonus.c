/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:30:35 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 14:48:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_coin_bonus(t_data *data)
{
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
}

void	init_torches_bonus(t_data *data)
{
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

void	init_sprites_bonus(t_data *data)
{
	init_torches_bonus(data);
	init_coin_bonus(data);
	data->img.exit_l = mlx_xpm_file_to_image(data->mlx, LOCKED,
			&data->img.width, &data->img.height);
	data->img.exit_u = mlx_xpm_file_to_image(data->mlx, EXIT,
			&data->img.width, &data->img.height);
}
