/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 10:39:26 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"


int	coinSprite_bonus(t_data *data, int width, int i)
{
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
	// while (j++ < 8000)
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin2, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
	// usleep(4000);
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin3, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
	// usleep(4000);
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin4, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
	// usleep(4000);
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin5, width, i * IMG_SIZE);
	// printf("je bugue\n");
	// usleep(11000);
	
	return (SUCCESS);
}

void	flamesSprite1(t_data *data, int width, int i)
{
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl2, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl3, width, i * IMG_SIZE);
	
}

void	flamesSprite2(t_data *data, int width, int i)
{
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr2, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr3, width, i * IMG_SIZE);
	
}

void	flamesSprite3(t_data *data, int width, int i)
{
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl2, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl3, width, i * IMG_SIZE);
	
}

void	flamesSprite4(t_data *data, int width, int i)
{
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br2, width, i * IMG_SIZE);
	for (int j = 0; j < 4000; j++)
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br3, width, i * IMG_SIZE);
	
}

void	displayWalls_bonus(t_data *data, int width, int i, int j)
{
	size_t k = j;
	
	if (i == 0 && k == 0) // Corner haut à gauche
		flamesSprite1(data, width, i);
	else if (i == 0 && k == ft_strlen(data->map.map[0]) - 2) // Corner haut à droite
		flamesSprite2(data, width, i);
	else if (i == data->map.line_count - 1 && k == 0) // Corner bas à gauche
		flamesSprite3(data, width, i);
	else if (i == data->map.line_count - 1 && k == ft_strlen(data->map.map[0]) - 2) // Corner bas droite
		flamesSprite4(data, width, i);
	else if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_t, 
					width, i * IMG_SIZE);
	else if (i == data->map.line_count - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_b, 
					width, i * IMG_SIZE);
	else if (k == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_l, 
					width, i * IMG_SIZE);
	else if (k == ft_strlen(data->map.map[0]) - 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_r, 
					width, i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 
					width, i * IMG_SIZE);
}

int	render_bonus(t_data *data)
{
	int 	i;
	int 	j;
	int		width;
	char	*steps_count;
	
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
				displayWalls_bonus(data, width, i, j);
			else if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->win, data->img.ground, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->win, data->img.player, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'F')
				mlx_put_image_to_window(data->mlx, data->win, data->img.foe, 
					width, i * IMG_SIZE);
			else if (data->map.map[i][j] == 'E')
			{
				if (data->map.can_exit == 0)
					mlx_put_image_to_window(data->mlx, data->win, data->img.exit_l, 
						width, i * IMG_SIZE);
				else
					mlx_put_image_to_window(data->mlx, data->win, data->img.exit_u, 
						width, i * IMG_SIZE);
			}	
			else if (data->map.map[i][j] == 'C')
				coinSprite_bonus(data, width, i);
			width += IMG_SIZE; 
			j++;
			steps_count = ft_itoa(data->steps_count);
			mlx_string_put(data->mlx, data->win, 115, 20, 206, "Counter:");
			mlx_string_put(data->mlx, data->win, 180, 20, 206, steps_count);
			if (steps_count)
				free(steps_count);
		}
		j = 0;
		width = 0;
		i++;
	}
	return (SUCCESS);
}
