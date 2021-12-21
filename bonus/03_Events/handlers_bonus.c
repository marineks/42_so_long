/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:11:52 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 15:29:46 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	handle_resize_bonus(t_data *data)
{
	render_bonus(data);
	return (0);
}

int	handle_keypress_bonus(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	else if (ft_strchr("wasd", keysym))
		movePlayer_bonus(data, keysym);
	else if (data->map.count_f && (keysym == ARROW_BOT || keysym == ARROW_TOP
			|| keysym == ARROW_LEFT || keysym == ARROW_RIGHT))
		moveFoe_bonus(data, keysym);
	return (0);
}

int	handle_btnrealease_bonus(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	return (0);
}
