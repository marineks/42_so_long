/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:56 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/14 18:09:53 by msanjuan         ###   ########.fr       */
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

void	movePlayer(t_data *data, char direction)
{
	if (checkCollision(data, direction) == FAILURE)
		return ;
	// if (winGame(data) == SUCCESS)
	// 	return ;
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
	data->map.map[data->map.p_i][data->map.p_j] = 'P';
	printf("ce que j'ai pour l'instant :%d | count_c : %d\n", data->map.collected, data->map.count_c);
	
}

void	collectCoins(t_data* data, char direction)
{
	// static int collected = 0;

	if (direction == 'D' && data->map.map[data->map.p_i][data->map.p_j + 1] == 'C')
		data->map.collected++;
	else if (direction == 'A' && data->map.map[data->map.p_i][data->map.p_j - 1] == 'C')
		data->map.collected++;
	else if (direction == 'S' && data->map.map[data->map.p_i + 1][data->map.p_j] == 'C')
		data->map.collected++;
	else if (direction == 'W' && data->map.map[data->map.p_i - 1][data->map.p_j] == 'C')
		data->map.collected++;
}