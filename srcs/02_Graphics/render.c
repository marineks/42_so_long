/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/17 15:04:34 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


int	coinSprite(t_data *data, int width, int i)
{
	// usleep(10000);
	
		mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, width, i * IMG_SIZE);
	// for (int j = 0; j < 4000; j++)
	// // usleep(10000);
	// // while (j++ < 8000)
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.coin2, width, i * IMG_SIZE);
	// for (int j = 0; j < 4000; j++)
	// // usleep(10000);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.coin3, width, i * IMG_SIZE);
	// for (int j = 0; j < 4000; j++)
	// // usleep(10000);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.coin4, width, i * IMG_SIZE);
	// for (int j = 0; j < 4000; j++)
	// // usleep(10000);
	// 	mlx_put_image_to_window(data->mlx, data->win, data->img.coin5, width, i * IMG_SIZE);
	// // printf("je bugue\n");
	// usleep(11000);
	
	return (SUCCESS);
}



void	displayWalls(t_data *data, int width, int i, int j)
{
	size_t k = j;
	
	if (i == 0 && k == 0) // Corner haut à gauche
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tl, 
					width, i * IMG_SIZE);
	else if (i == 0 && k == ft_strlen(data->map.map[0]) - 2) // Corner haut à droite
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_tr, 
					width, i * IMG_SIZE);
	else if (i == data->map.line_count - 1 && k == 0) // Corner bas à gauche
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_bl, 
					width, i * IMG_SIZE);
	else if (i == data->map.line_count - 1 && k == ft_strlen(data->map.map[0]) - 2) // Corner bas droite
		mlx_put_image_to_window(data->mlx, data->win, data->img.corner_br, 
					width, i * IMG_SIZE);
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
}

int	render(t_data *data)
{
	int 	i;
	int 	j;
	int		width;
	
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
			{
				displayWalls(data, width, i, j);
				// mlx_put_image_to_window(data->mlx, data->win, data->img.wall, 
				// 	width, i * IMG_SIZE);
			}
				
			// else if (data->map.map[i][j] == '0')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.ground, 
			// 		width, i * IMG_SIZE);
			// else if (data->map.map[i][j] == 'P')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.player, 
			// 		width, i * IMG_SIZE);
			// else if (data->map.map[i][j] == 'E')
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.exit, 
			// 		width, i * IMG_SIZE);
			// else if (data->map.map[i][j] == 'C') // collectibles != collectés
			// {
			// 	// coinSprite(data, width, i);
			// 	mlx_put_image_to_window(data->mlx, data->win, data->img.coin1, 
			// 		width, i * IMG_SIZE);
			// }
			width += IMG_SIZE; 
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	// mlx_string_put(data->mlx, data->win, 15, 15, 231, "Counter:");
	// mlx_string_put(data->mlx, data->win, 80, 15, 231, ft_itoa(data->steps_count));
	return (SUCCESS);
}
