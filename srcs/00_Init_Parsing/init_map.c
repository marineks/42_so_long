/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:29:54 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 16:12:53 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../includes/get_next_line.h"

void	init_map(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->map.count_p = 0;
	data->map.count_e = 0;
	data->map.count_c = 0;
	data->map.collected = 0;
	data->map.can_exit = 0;
	data->steps_count = 0;
	data->win_height = data->map.line_count * IMG_SIZE;
	data->win_width = (ft_strlen(data->map.map[0]) - 1) * IMG_SIZE;
	data->img.height = IMG_SIZE;
	data->img.width = IMG_SIZE;
}
