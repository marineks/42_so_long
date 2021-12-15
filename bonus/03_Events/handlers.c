/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:11:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 10:55:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	handle_resize(t_data *data)
{
	render(data);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (keysym == ARROW_TOP || keysym == W)
		movePlayer(data, 'W');
	else if (keysym == ARROW_BOT || keysym == S)
		movePlayer(data, 'S');
	else if (keysym == ARROW_LEFT || keysym == A)
		movePlayer(data, 'A');
	else if (keysym == ARROW_RIGHT || keysym == D)
		movePlayer(data, 'D');
	return (0);
}

int	handle_btnrealease(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	return (0);
}