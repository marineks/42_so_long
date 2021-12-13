/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/13 20:29:58 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc == 2)
	{
		if (check_extension(argv[1]) == FAILURE)
			error_msg("Argument is not a correct .ber file.\n",& data);
		data.map.line_count = retrieveLineNumber(argv[1]);
		createMap(argv[1], &data);
		initMap(&data);
		// printMap(&data);
		checkMap(&data);
	
	
		// establishes a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance
		data.mlx = mlx_init();
		if (data.mlx == NULL)
			return (ERROR);
			
		// will return a pointer to the window just created
		data.win = mlx_new_window(data.mlx, data.map.win_width, data.map.win_height, "Mon potit jeu");
		if (data.win == NULL)
		{
			free(data.win);
			return (ERROR);
		}


		data.img.wall = mlx_xpm_file_to_image(data.mlx, WALL, &data.img.width, &data.img.height);
		data.img.ground = mlx_xpm_file_to_image(data.mlx, GROUND, &data.img.width, &data.img.height);
		data.img.exit = mlx_xpm_file_to_image(data.mlx, EXIT, &data.img.width, &data.img.height);
		data.img.coin = mlx_xpm_file_to_image(data.mlx, COIN, &data.img.width, &data.img.height);
		data.img.player = mlx_xpm_file_to_image(data.mlx, PLAYER, &data.img.width, &data.img.height);

		// is triggered when there's no event processed
		mlx_loop_hook(data.mlx, &render, &data);
		
		// to get the proper events
		mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
		// mlx_hook(data.win, ButtonRelease, ButtonReleaseMask, &handle_btnrealease, &data); 
		// // mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
		mlx_hook(data.win, ClientMessage, LeaveWindowMask, &handle_btnrealease, &data);
		//initiates the window rendering
		mlx_loop(data.mlx);
		
		// We must detroy the display (which basically refers to the connexion identifier used to communicate with the X Server).
		mlx_destroy_image(data.mlx, data.img.wall);
		mlx_destroy_image(data.mlx, data.img.ground);
		mlx_destroy_image(data.mlx, data.img.player);
		mlx_destroy_image(data.mlx, data.img.exit);
		mlx_destroy_image(data.mlx, data.img.coin);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		if (data.map.map)
			ft_free(data.map.map);
	}
}
	
	
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, RED_PIXEL);
	// mlx_put_image_to_window(data.mlx_ptr, data.win, img.img, 0, 0);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel,
			// &data.img.line_length, &data.img.endian);



	// fd = open(argv[1], O_RDONLY);
	// 	if (fd < 0)
	// 		printf("\e[31mError: open failed\e[0m\n");
	// 	else
	// 	{
	// 		while ((line = get_next_line(fd)) != NULL)
	// 		{
	// 			// printf("\e[32mLine:\e[0m [%s]\n", line);
	// 			line_count++;
	// 			free(line);
	// 		}
	// 		if (!line) 
	// 		{
	// 			// printf("\e[35mCall after EOF was reached:\e[1;31m [%s]\n", line);
	// 			free(line);
	// 		}
	// 		// printf("\e[0m\n");
	// 		close(fd);
	// 	}