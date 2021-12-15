/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:06:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/15 11:06:01 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000        /* must be a directory */
# endif

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0
// # define IMG_W 48
// # define IMG_H 48
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define GREEN "\033[1;32m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"
# define PINK "\033[38;5;206m"
# define PEACH "\033[38;5;217m"
# define ARROW_TOP 65362
# define ARROW_BOT 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define A 97
# define D 100
# define S 115
# define W 119
# define PLAYER "assets/maskdude.xpm"
# define EXIT "assets/exit.xpm"
# define COIN "assets/collectible.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define ERROTHER "At least one character of the map is not valid.\n"
# define ERRCHARS "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define ERRPLAYER "This is a solo campaign...\n"
# define ERRREC "The map is not a rectangle.\n"
# define ERREDGES "The edges of the map are invalid (must be walls -1-)\n"

typedef struct s_map
{
	int 	fd;
	int		line_count;
	size_t	line_len;
	int 	count_p;
	int 	count_e;
	int 	count_c;
	char 	*path;
	char	**map;
	int		win_height;
	int		win_width;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_img
{
	void	*mlx_img; // refers to the address the func mlx_new_image returns
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	void	*coin;
	char	*addr; // index = line_len * y + x * (bpp / 8)
	int		bits_per_pixel; 
	int		line_length; // amount of bytes taken by one row of our image. = image_width * (bpp / 8)
	int		endian; // means that the bytes in computer memory are read in a certain order. Big-endian (BE) and Little-endian (LE).
}	t_img;

typedef struct	s_data 
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	t_img	img;
	t_map	map;
	
}				t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}				t_rect;

/*
**
**  00_INIT_PARSING
**
*/
/* ******** create_map.c ********/
int		retrieveLineNumber(char *path);
void	createMap(char *path, t_data *data);
void	ft_free(char **tab);

/* ******** printmap.c ********/
void	parseMap(t_data *data);

/* ******** printmap.c ********/
void	printMap(t_data *data);
void	initMap(t_data *data);
/*
**
**  01_ERRORS
**
*/
/* ******** error_msg.c ********/
void	error_msg(char *str, t_data *data);

/* ******** check_ber.c ********/
int		check_extension(char *path);

/* ******** check_map.c ********/
int		checkMap(t_data *data);
int		checkChars(t_data *data);
int		checkRectangle(t_data *data);
int		checkEdges(int line_count, char **map);
int 	checkTopBot(int row, char **map);
/*
**
**  02_GRAPHICS
**
*/
/* ******** Pixel_utils.c ********/
void	img_pix_put(t_img *img, int x, int y, int color);

/* ******** Render.c ********/
int		render(t_data *data);
void	render_background(t_img *img, int color);


/*
**
**  03_EVENTS
**
*/
/* ******** Handlers.c ********/
int		handle_keypress(int keysym, t_data *data);
int		handle_resize(t_data *data);
int		handle_btnrealease(t_data *data);

void	move_msg(t_data *data);

void	movePlayer(t_data *data, char direction);
int		checkCollision(t_data *data, char direction);
void	collectCoins(t_data* data, char direction);
int		crossExit(t_data* data, char direction);
int		winGame(t_data *data);
int		checkNextTile(t_data *data, char direction, char tile);
#endif