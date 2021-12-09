/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:06:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/09 14:59:23 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "../libft/libft.h"

# define RED_PIXEL 0xFF0000
# define BLUE_PIXEL 0x9CC2F7
# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define ERROR -1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_img
{
	void	*mlx_img; // refers to the address the func mlx_new_image returns
	char	*addr; // index = line_len * y + x * (bpp / 8)
	int		bits_per_pixel; 
	int		line_length; // amount of bytes taken by one row of our image. = image_width * (bpp / 8)
	int		endian; // means that the bytes in computer memory are read in a certain order. Big-endian (BE) and Little-endian (LE).
}	t_img;

typedef struct	s_data 
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	
}				t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

/*
**
**  00_INIT_PARSING
**
*/
/* ******** create_map.c ********/
int		retrieveLineNumber(char *path);
char**	createMap(char *path, int line_count);

/* ******** printmap.c ********/
void	printMap(int line_count, char **map);

/*
**
**  02_GRAPHICS
**
*/
/* ******** Pixel_utils.c ********/
void	img_pix_put(t_img *img, int x, int y, int color);

/* ******** Render.c ********/
int		render(t_data *data);
int		render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);


/*
**
**  03_EVENTS
**
*/
/* ******** Handlers.c ********/
int		handle_keypress(int keysym, t_data *data);

#endif