/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:10:12 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 15:23:35 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	display_walls_bonus(t_data *data, int width, int i, int j)
{
	if (i == 0 && j == 0)
		flamesSprite1(data, width, i);
	else if (i == 0 && j == ft_strlen(data->map.map[0]) - 2)
		flamesSprite2(data, width, i);
	else if (i == data->map.line_count - 1 && j == 0)
		flamesSprite3(data, width, i);
	else if (i == data->map.line_count - 1
		&& j == ft_strlen(data->map.map[0]) - 2)
		flamesSprite4(data, width, i);
	else if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_t,
			width, i * IMG_SIZE);
	else if (i == data->map.line_count - 1)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_b,
			width, i * IMG_SIZE);
	else if (j == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_l,
			width, i * IMG_SIZE);
	else if (j == ft_strlen(data->map.map[0]) - 2)
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall_r,
			width, i * IMG_SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall,
			width, i * IMG_SIZE);
}

void	parse_chars(t_data *data, int width, int i, int j)
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
}

void	display_counter_window(t_data *data)
{
	char	*steps_count;

	steps_count = ft_itoa(data->steps_count);
	mlx_string_put(data->mlx, data->win, 115, 20, 206, "Counter:");
	mlx_string_put(data->mlx, data->win, 180, 20, 206, steps_count);
	if (steps_count)
		free(steps_count);
}

int	render_bonus(t_data *data)
{
	int		i;
	size_t	j;
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
			parse_chars(data, width, i, j);
			width += IMG_SIZE;
			j++;
			display_counter_window(data);
		}
		j = 0;
		width = 0;
		i++;
	}
	return (SUCCESS);
}
