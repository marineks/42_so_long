/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:28:46 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 15:27:25 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

/*
**	Function which checks the next Tile
*/
int	check_next_tile_foe_bonus(t_data *data, int direction, char tile)
{
	if ((direction == ARROW_RIGHT
			&& data->map.map[data->f_i][data->f_j + 1] == tile)
		|| (direction == ARROW_LEFT
		&& data->map.map[data->f_i][data->f_j - 1] == tile)
		|| (direction == ARROW_BOT
		&& data->map.map[data->f_i + 1][data->f_j] == tile)
		|| (direction == ARROW_TOP
		&& data->map.map[data->f_i - 1][data->f_j] == tile))
		return (SUCCESS);
	else
		return (FAILURE);
}

/*
**	Function that quits the game when the foes touches the player
*/
int	lose_game_bonus(t_data *data)
{
	printf("\033[0;31mGAME OVER LOSER\n\n\033[0m");
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}

/*
**	Function which is the "hub" of all the (non)possible moves of the foe. 
*/
void	move_foe_bonus(t_data *data, int direction)
{
	if (checkNextTileFoe_bonus(data, direction, '1') == SUCCESS
		|| checkNextTile_bonus(data, direction, 'E') == SUCCESS
		|| checkNextTileFoe_bonus(data, direction, 'C') == SUCCESS)
		return ;
	if (checkNextTileFoe_bonus(data, direction, 'P') == SUCCESS)
		loseGame_bonus(data);
	data->map.map[data->f_i][data->f_j] = '0';
	if (direction == ARROW_RIGHT)
		data->f_j++;
	else if (direction == ARROW_LEFT)
		data->f_j--;
	else if (direction == ARROW_BOT)
		data->f_i++;
	else if (direction == ARROW_TOP)
		data->f_i--;
	data->map.map[data->f_i][data->f_j] = 'F';
}
