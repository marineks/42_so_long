/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:16:56 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 15:35:12 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*
**	Function which checks the next Tile
*/
int	check_next_tile_bonus(t_data *data, char direction, char tile)
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
void	collect_coins_bonus(t_data *data, char direction)
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
int	win_game_bonus(t_data *data)
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
void	move_player_bonus(t_data *data, char direction)
{
	if (checkNextTile_bonus(data, direction, '1') == SUCCESS
		|| checkNextTile_bonus(data, direction, 'F') == SUCCESS
		|| (data->map.can_exit == 0
			&& checkNextTile_bonus(data, direction, 'E') == SUCCESS))
		return ;
	data->steps_count++;
	collectCoins_bonus(data, direction);
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
	move_msg_bonus(data);
	if (data->map.can_exit == 1 && data->map.map[data->p_i][data->p_j] == 'E')
		winGame_bonus(data);
	data->map.map[data->p_i][data->p_j] = 'P';
}
