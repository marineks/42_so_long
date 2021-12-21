/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/20 14:04:09 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"
#include "../includes/get_next_line.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		if (check_extension_bonus(argv[1]) == FAILURE)
			error_msg_bonus(ERRBER, &data);
		createMap_bonus(argv[1], &data);
		initMap_bonus(&data);
		checkMap_bonus(&data);
		init_window_bonus(&data);
		init_images_bonus(&data);
		render_bonus(&data);
		loop_images_bonus(data);
		destroy_images_bonus(data);
		free(data.mlx);
		if (data.map.map)
			ft_free_bonus(data.map.map);
	}
}
	