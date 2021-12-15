/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 15:16:59 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		if (check_extension(argv[1]) == FAILURE)
			error_msg(ERRBER, &data);
		createMap(argv[1], &data);
		initMap(&data);
		checkMap(&data);
		init_window(&data);
		init_images(&data);
		loop_images(data);
		destroy_images(data);
		free(data.mlx);
		if (data.map.map)
			ft_free(data.map.map);
	}
}
	