/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:29:54 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/10 18:38:24 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

void	initMap(t_data *data)
{
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	// data->map.ground_path = "assets/ground.xpm";
	// data->map.wall_path = "assets/wall.xpm";
	// data->map.exit_path = "assets/exit.xpm";
	// data->map.player_path = "assets/player.xpm";
	// data->map.collectible_path = "assets/collectible.xpm";
}