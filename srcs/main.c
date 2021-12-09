/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 11:05:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(void)
{
	t_data data;
	
	// establishes a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (ERROR);
		
	// will return a pointer to the window just created
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (ERROR);
	}

	// char	*relative_path = "../assets/test.xpm";
	int		img_width = 60;
	int		img_height = 60;
	/* mlx_xpm_file_to_image() creates a new image in memory, using the specified xpm_data. 
		   It returns a void * identifier needed to manipulate this image later. */
	data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, "/mnt/nfs/homes/msanjuan/Documents/Projets_Github/42_so_long/assets/test.xpm", &img_width, &img_height);

	// is triggered when there's no event processed
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	
	// to get the proper events
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
	// // mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	
	//initiates the window rendering
	mlx_loop(data.mlx_ptr);
	
	// We must detroy the display (which basically refers to the connexion identifier used to communicate with the X Server).
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
	
	
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, RED_PIXEL);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bits_per_pixel,
			// &data.img.line_length, &data.img.endian);