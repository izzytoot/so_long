/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:27 by root              #+#    #+#             */
/*   Updated: 2025/01/23 19:11:29 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

/* ************************************************************************** */
/*                                    MACROS                                  */
/* ************************************************************************** */

# define TILE_SIZE	32
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"  
# define YELLOW		"\033[0;33m" 
# define RESET		"\033[0m"
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_ESC	65307
# define KEY_LEFT	65361
# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

/* ************************************************************************** */
/*                                    STRUCTS                                 */
/* ************************************************************************** */

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_images
{
	void		*super_kiwi;
	void		*tile;
	void		*water;
	void		*kiwi_fruit;
	void		*box_closed;
	void		*box_open;
}	t_images;

typedef struct s_game
{
	int			fd;
	char		**map;
	int			map_height;
	int			map_width;
	int			nb_players;
	int			nb_exit;
	int			nb_collectables;
	bool		exit_access;
	t_position	pos_p;
	t_position	pos_e;
	t_position	*pos_c;
	void		*mlx;
	void		*win;
	t_images	*img;
	bool		start;
	bool		open_box;
	int			nb_moves;
	t_position	pos_player;
}	t_game;

/* ************************************************************************** */
/*                                 PROTOTYPES                                 */
/* ************************************************************************** */

//01. map_read_and_load.c
int		map_loading(t_game *game, char *map_file);
int		load_line_to_map(t_game *game, char *line);
int		width_of_map(char *str);

//02. map_error_check.c
int		check_form(t_game *game);
int		check_walls(t_game *game);
int		check_e_p(t_game *game);
int		check_c(t_game *game);
int		check_map_errors(t_game *game);

//03. map_access_check.c
int		map_access_check(t_game *game);
void	flood_fill(t_game *game, t_position	starting_point, char target);

//04. parsing_utils.c
t_game	set_game_start(t_game *game);
void	assign_p_e(t_game *game, int y, int x, char c);
void	assign_c(t_game *game);
void	copy_map(t_game	*original_game, t_game *temp_game);
void	copy_pos_c(t_game	*original_game, t_game *temp_game);

//05.start_game.c
void	open_game(t_game *game);
void	upload_images(t_game *game);
void	place_image(t_game *game, int y, int x);
void	user_controls(t_game *game);

//06. play_game.c
int		key_controls(int keycode, t_game *game);
int		vertical_moves_up(t_game *game);
int		vertical_moves_down(t_game *game);
int		horizontal_moves_right(t_game *game);
int		horizontal_moves_left(t_game *game);
int		move_player(t_game *game, int y, int x);

//07.game_utils.c
void	render_map(t_game *game);
void	getting_closer(t_game *game);
int		main_loop(t_game *game);
int		close_window(void *param);

//08.free_clear_and_close.c
void	close_temp_game(t_game *temp_game);
void	clear_game(t_game *game);
void	kill_game_visuals(t_game *game);
void	close_game(t_game *game, char *message);

#endif