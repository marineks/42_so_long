/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:06:24 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/21 16:11:39 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

# define ERROR -1
# define FAILURE 1
# define SUCCESS 0
# define IMG_SIZE 48
# define TITRE "Treasure"
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
# define FOE "assets/foe.xpm"
# define PLAYER "assets/player.xpm"
# define EXIT "assets/chest_unlocked.xpm"
# define LOCKED "assets/chest_locked.xpm"
# define WALL "assets/wall.xpm"
# define GROUND "assets/ground.xpm"
# define COIN1 "assets/coin/coin1.xpm"
# define COIN2 "assets/coin/coin2.xpm"
# define COIN3 "assets/coin/coin3.xpm"
# define COIN4 "assets/coin/coin4.xpm"
# define COIN5 "assets/coin/coin5.xpm"
# define W_TOP "assets/walls/wall_t.xpm"
# define W_BOT "assets/walls/wall_b.xpm"
# define W_LEFT "assets/walls/wall_l.xpm"
# define W_RIGHT "assets/walls/wall_r.xpm"
# define C_TL "assets/walls/corner_tl.xpm"
# define C_TL2 "assets/walls/corner_tl2.xpm"
# define C_TL3 "assets/walls/corner_tl3.xpm"
# define C_TR "assets/walls/corner_tr.xpm"
# define C_TR2 "assets/walls/corner_tr2.xpm"
# define C_TR3 "assets/walls/corner_tr3.xpm"
# define C_BL "assets/walls/corner_bl.xpm"
# define C_BL2 "assets/walls/corner_bl2.xpm"
# define C_BL3 "assets/walls/corner_bl3.xpm"
# define C_BR "assets/walls/corner_br.xpm"
# define C_BR2 "assets/walls/corner_br2.xpm"
# define C_BR3 "assets/walls/corner_br3.xpm"
# define W_RAND "assets/walls/wall_random.xpm"
# define ERRBER "Argument is not a correct .ber file.\n"
# define ERROTHER "At least one character of the map is not valid.\n"
# define ERRCHARS "One of the characters \"0, 1, P, C, E\" is missing.\n"
# define ERRPLAYER "This is a solo campaign...\n"
# define ERRPLAYERB "There can be only one player on each side...\n"
# define ERRREC "The map is not a rectangle.\n"
# define ERREDGES "The edges of the map are invalid (must be walls -1-)\n"

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit_l;
	void	*ground;
	void	*player;
	int		line_length;
	void	*coin1;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;

}				t_data;

/*
**
**  00_INIT_PARSING
**
*/
int		retrieve_line_number(char *path);
void	create_map(char *path, t_data *data);
void	put_input_in_map(int row, int column, int i, t_data *data);
void	ft_free(char **tab);
void	parse_map(t_data *data);
void	init_map(t_data *data);
void	init_player(t_data *data);
/*
**
**  01_ERRORS
**
*/
void	error_msg(char *str, t_data *data);
int		check_extension(char *path);
int		check_map(t_data *data);
int		check_chars(t_data *data);
int		check_rectangle(t_data *data);
int		check_edges(int line_count, char **map);
int		check_top_bot(int row, char **map);
/*
**
**  02_GRAPHICS
**
*/
int		render(t_data *data);
void	parse_chars(t_data *data, int width, int i, int j);
int		init_window(t_data *data);
void	init_images(t_data *data);
void	loop_images(t_data data);
void	destroy_images(t_data data);
/*
**
**  03_EVENTS
**
*/
int		handle_keypress(int keysym, t_data *data);
int		handle_btnrealease(t_data *data);
void	move_msg(t_data *data);
void	move_player(t_data *data, char direction);
void	collect_coins(t_data *data, char direction);
int		win_game(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);

#endif