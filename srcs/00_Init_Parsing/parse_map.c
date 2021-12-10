/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:38:45 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/10 19:25:51 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

// void	parseMap(t_data *data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
	// while (data->map.map[i])
	// 	{
	// 		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
	// 		{
	// 			if (data->map.map[i][j] == '1')
	// 			{
	// 				data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &img_width, &img_height);
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, size, i * 48);
	// 			}
	// 			else if (data->map.map[i][j] == '0')
	// 			{
	// 				data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, GROUND, &img_width, &img_height);
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, size, i * 48);
	// 			}
	// 			else if (data->map.map[i][j] == 'P')
	// 			{
	// 				data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &img_width, &img_height);
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, size, i * 48);
	// 			}
	// 			else if (data->map.map[i][j] == 'E')
	// 			{
	// 				data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &img_width, &img_height);
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, size, i * 48);
	// 			}
	// 			else if (data->map.map[i][j] == 'C')
	// 			{
	// 				data->img.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECTIBLE, &img_width, &img_height);
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, size, i * 48);
	// 			}
	// 			size += 48; 
	// 			j++;
	// 		}
	// 		j = 0;
	// 		size = 0;
	// 		i++;
	// 	}
// }