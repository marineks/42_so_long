/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:28 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include <unistd.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define ERROR -1

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;
	// establishes a connection to the correct graphical system and will return a void * which holds the location of our current MLX instance
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (ERROR);
	// will return a pointer to the window just created
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (ERROR);
	}
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);

	//initiates the window rendering
	mlx_loop(mlx_ptr);
	// frees all the ressources that have been allocated for the window when it is no longer needed.
	mlx_destroy_window(mlx_ptr, win_ptr);
	// We must detroy the display (which basically refers to the connexion identifier used to communicate with the X Server).
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}