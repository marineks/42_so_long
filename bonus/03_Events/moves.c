/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:56 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 10:31:10 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
**	Function which checks whether the player is going to step on a 'Wall' tile
*/
int	checkCollision(t_data *data, char direction)
{
	if (direction == 'D' && data->map.map[data->p_i][data->p_j + 1] == '1')
		return (FAILURE);
	else if (direction == 'A' && data->map.map[data->p_i][data->p_j - 1] == '1')
		return (FAILURE);
	else if (direction == 'S' && data->map.map[data->p_i + 1][data->p_j] == '1')
		return (FAILURE);
	else if (direction == 'W' && data->map.map[data->p_i - 1][data->p_j] == '1')
		return (FAILURE);
	return (SUCCESS);
}

/*
**	Function that checks that, when the player moves, the next tile is a coin.
**	Should it be the case, the counter of all the collected coins increases.
*/
void	collectCoins(t_data* data, char direction)
{
	if ((direction == 'D' && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 'A' && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 'S' && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 'W' && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
}

/*
**	Function which prevents the player from stepping on the exit when they have
**	not collected all the coins in the map.
*/
int		crossExit(t_data* data, char direction)
{
	if ((direction == 'D' && data->map.map[data->p_i][data->p_j + 1] == 'E')
		|| (direction == 'A' && data->map.map[data->p_i][data->p_j - 1] == 'E')
		|| (direction == 'S' && data->map.map[data->p_i + 1][data->p_j] == 'E')
		|| (direction == 'W' && data->map.map[data->p_i - 1][data->p_j] == 'E'))
		return (SUCCESS);
	else
		return (FAILURE);
}

/*
**	Function that quits the game when the player steps on the exit and has
**	collected all the coins in the map.
*/
int		winGame(t_data *data)
{
	if (data->map.can_exit == 1)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
		return (SUCCESS);
	}
	else
		return (FAILURE);
}

/*
**	Function which is the "hub" of all the (non)possible moves of the player.
**	Also counts and display the players's steps counter. 
*/
void	movePlayer(t_data *data, char direction)
{
	if (checkCollision(data, direction) == FAILURE 
		|| (data->map.can_exit == 0 && crossExit(data, direction) == SUCCESS))
		return ;
	data->steps_count++;
	collectCoins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (direction == 'D')
		data->p_j++;
	else if (direction == 'A')
		data->p_j--;
	else if (direction == 'S')
		data->p_i++;
	else if (direction == 'W')
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		winGame(data);
	data->map.map[data->p_i][data->p_j] = 'P';
}
