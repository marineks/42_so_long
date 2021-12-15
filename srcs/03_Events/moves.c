/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:56 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 09:31:21 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	checkCollision(t_data *data, char direction)
{
	if (direction == 'D' && data->map.map[data->map.p_i][data->map.p_j + 1] == '1')
		return (FAILURE);
	else if (direction == 'A' && data->map.map[data->map.p_i][data->map.p_j - 1] == '1')
		return (FAILURE);
	else if (direction == 'S' && data->map.map[data->map.p_i + 1][data->map.p_j] == '1')
		return (FAILURE);
	else if (direction == 'W' && data->map.map[data->map.p_i - 1][data->map.p_j] == '1')
		return (FAILURE);
	return (SUCCESS);
}

int		winGame(t_data *data)
{
	if (data->map.able_to_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

int		crossExit(t_data* data, char direction)
{
	if ((direction == 'D' && data->map.map[data->map.p_i][data->map.p_j + 1] == 'E')
		|| (direction == 'A' && data->map.map[data->map.p_i][data->map.p_j - 1] == 'E')
		|| (direction == 'S' && data->map.map[data->map.p_i + 1][data->map.p_j] == 'E')
		|| (direction == 'W' && data->map.map[data->map.p_i - 1][data->map.p_j] == 'E'))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	lockEnding(t_data* data, char direction)
{
	data->map.map[data->map.p_i][data->map.p_j] = 'E';
	if (direction == 'D')
		data->map.p_j = data->map.p_j + 1;
	else if (direction == 'A')
		data->map.p_j = data->map.p_j - 1;
	else if (direction == 'S')
		data->map.p_i = data->map.p_i + 1;
	else if (direction == 'W')
		data->map.p_i = data->map.p_i - 1;
	data->map.map[data->map.p_i][data->map.p_j] = 'P';	
}

void	movePlayer(t_data *data, char direction)
{
	if (checkCollision(data, direction) == FAILURE 
		|| (data->map.able_to_exit == 0 
		&& crossExit(data, direction) == SUCCESS))
		return ;
	collectCoins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.able_to_exit = 1;
	data->map.map[data->map.p_i][data->map.p_j] = '0';
	if (direction == 'D')
		data->map.p_j = data->map.p_j + 1;
	else if (direction == 'A')
		data->map.p_j = data->map.p_j - 1;
	else if (direction == 'S')
		data->map.p_i = data->map.p_i + 1;
	else if (direction == 'W')
		data->map.p_i = data->map.p_i - 1;
	if (data->map.able_to_exit == 1 && data->map.map[data->map.p_i][data->map.p_j] == 'E')
		winGame(data);
	data->map.map[data->map.p_i][data->map.p_j] = 'P';	
}

void	collectCoins(t_data* data, char direction)
{
	if (direction == 'D' && data->map.map[data->map.p_i][data->map.p_j + 1] == 'C')
		data->map.collected++;
	else if (direction == 'A' && data->map.map[data->map.p_i][data->map.p_j - 1] == 'C')
		data->map.collected++;
	else if (direction == 'S' && data->map.map[data->map.p_i + 1][data->map.p_j] == 'C')
		data->map.collected++;
	else if (direction == 'W' && data->map.map[data->map.p_i - 1][data->map.p_j] == 'C')
		data->map.collected++;
}