/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:11:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/14 15:36:52 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	swapPlayer(t_data *data, char direction)
{
	if (checkCollision(data, direction) == FAILURE)
			return ;
	if (direction == 'D')
	{
		data->map.map[data->map.p_i][data->map.p_j] = '0';
		data->map.p_j = data->map.p_j + 1;
		data->map.map[data->map.p_i][data->map.p_j] = 'P';
	}
	else if (direction == 'A')
	{
		data->map.map[data->map.p_i][data->map.p_j] = '0';
		data->map.p_j = data->map.p_j - 1;
		data->map.map[data->map.p_i][data->map.p_j] = 'P';
	}
	else if (direction == 'S')
	{
		data->map.map[data->map.p_i][data->map.p_j] = '0';
		data->map.p_i = data->map.p_i + 1;
		data->map.map[data->map.p_i][data->map.p_j] = 'P';
	} 
	else if (direction == 'W')
	{
		data->map.map[data->map.p_i][data->map.p_j] = '0';
		data->map.p_i = data->map.p_i - 1;
		data->map.map[data->map.p_i][data->map.p_j] = 'P';
	}
}

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}


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

int	handle_keypress(int keysym, t_data *data)
{
	// printf("keysym = %d\n", keysym);
	// frees all the ressources that have been allocated for the window when it is no longer needed.
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL; // set to NULL after the call to mlx_destroy_window to make the "mlx put pixel" check actually works.
	}
	else if (keysym == ARROW_TOP || keysym == W)
	{
		// if (checkCollision(data, 'W') == FAILURE)
		// 	return (ERROR);
		swapPlayer(data, 'W');
	}
	else if (keysym == ARROW_BOT || keysym == S)
	{
		// if (checkCollision(data, 'S') == FAILURE)
		// 	return (ERROR);
		swapPlayer(data, 'S');
	}
	else if (keysym == ARROW_LEFT || keysym == A)
	{
		// if (checkCollision(data, 'A') == FAILURE)
		// 	return (ERROR);
		swapPlayer(data, 'A');
	}
	else if (keysym == ARROW_RIGHT || keysym == D)
	{
		// if (checkCollision(data, 'D') == FAILURE)
		// 	return (ERROR);
		swapPlayer(data, 'D');
	}
	return (0);
}

int	handle_btnrealease(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	
	return (0);
}