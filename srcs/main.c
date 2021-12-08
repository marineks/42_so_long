/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:38:14 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/08 17:50:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../mlx_linux/mlx.h"
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>

# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x9CC2F7
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define ERROR -1

typedef struct	s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	
}				t_data;

typedef struct s_img
{
	void	*mlx_img; // refers to the address the func mlx_new_image returns
	char	*addr; // index = line_len * y + x * (bpp / 8)
	int		bits_per_pixel; // 
	int		line_length; // amount of bytes taken by one row of our image. = image_width * (bpp / 8)
	int		endian;
}	t_img;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)pixel = color;
}

int	handle_keypress(int keysym, t_data *data)
{
	// frees all the ressources that have been allocated for the window when it is no longer needed.
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // set to NULL after the call to mlx_destroy_window to make the "mlx put pixel" check actually works.
	}
	printf("Keypress: %d\n", keysym);
	return (0);
}

int render_rect(t_data *data, t_rect rect)
{
	int	vertical;
	int horizontal;

	if (data->win_ptr == NULL)
		return (1);
	vertical = rect.y;
	while (vertical < rect.y + rect.height)
	{
		horizontal = rect.x;
		while (horizontal < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, horizontal++, vertical, rect.color);
		++vertical;
	}
	return (0);
}

int	render(t_data *data)
{
	// if (data->win_ptr != NULL) /* if window has been destroyed, we don't want to put the pixel ! */
	// 	mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
	// 		WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	if (data->win_ptr != NULL)
	{
		// (t_rect){} is what is called a compound literal. 
		// Since C99, this is a way to initialize structures without having to manually assign each member. 
		// I'm directly passing a structure by value here
		render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, BLUE_PIXEL});
		render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});
	}
	return (0);
}

int main(void)
{
	t_data	img;
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

	// void	*mlx_new_image(void *mlx_ptr,int width,int height);
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);


	// img.img = mlx_new_image(data.mlx_ptr, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// my_mlx_pixel_put(&img, 5, 5, RED_PIXEL);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img.img, 0, 0);

	// is triggered when there's no event processed
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	
	// to get the proper events
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); 
	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);
	
	//initiates the window rendering
	mlx_loop(data.mlx_ptr);
	
	// We must detroy the display (which basically refers to the connexion identifier used to communicate with the X Server).
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}