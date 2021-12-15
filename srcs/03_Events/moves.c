/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:56 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 11:08:01 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

/*
**	Function which checks the next Tile
*/
int	checkNextTile(t_data *data, char direction, char tile)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == tile)
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == tile)
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == tile)
		|| (direction == 'w' && data->map.map[data->p_i - 1][data->p_j] == tile)
		)
		return (SUCCESS);
	else
		return (FAILURE);
}

/*
**	Function that checks that, when the player moves, the next tile is a coin.
**	Should it be the case, the counter of all the collected coins increases.
*/
void	collectCoins(t_data* data, char direction)
{
	if ((direction == 'd' && data->map.map[data->p_i][data->p_j + 1] == 'C')
		|| (direction == 'a' && data->map.map[data->p_i][data->p_j - 1] == 'C')
		|| (direction == 's' && data->map.map[data->p_i + 1][data->p_j] == 'C')
		|| (direction == 'w' && data->map.map[data->p_i - 1][data->p_j] == 'C'))
		data->map.collected++;
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
	if (checkNextTile(data, direction, '1') == SUCCESS 
		|| (data->map.can_exit == 0 
		&& checkNextTile(data, direction, 'E') == SUCCESS))
		return ;
	data->steps_count++;
	collectCoins(data, direction);
	if (data->map.collected == data->map.count_c)
		data->map.can_exit = 1;
	data->map.map[data->p_i][data->p_j] = '0';
	if (direction == 'd')
		data->p_j++;
	else if (direction == 'a')
		data->p_j--;
	else if (direction == 's')
		data->p_i++;
	else if (direction == 'w')
		data->p_i--;
	move_msg(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		winGame(data);
	data->map.map[data->p_i][data->p_j] = 'P';
}
