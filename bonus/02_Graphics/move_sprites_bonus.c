/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprites_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:51:06 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 14:55:47 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	coin_sprite_bonus(t_data *data, int width, int i)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.coin2, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.coin3, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.coin4, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.coin5, width,
		i * IMG_SIZE);
	usleep(4000);
	return (SUCCESS);
}

void	flames_sprite1(t_data *data, int width, int i)
{
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl2, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl3, width,
		i * IMG_SIZE);
}

void	flames_sprite2(t_data *data, int width, int i)
{
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr2, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr3, width,
		i * IMG_SIZE);
}

void	flames_sprite3(t_data *data, int width, int i)
{
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl2, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl3, width,
		i * IMG_SIZE);
}

void	flames_sprite4(t_data *data, int width, int i)
{
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br2, width,
		i * IMG_SIZE);
	usleep(4000);
	mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br3, width,
		i * IMG_SIZE);
}
