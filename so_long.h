/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:27 by root              #+#    #+#             */
/*   Updated: 2025/01/21 17:35:27 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define TILE_SIZE 32

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


/* ************************************************************************** */
/*                                    STRUCTS                                 */
/* ************************************************************************** */

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_game
{
	int			fd;
	char		**map;
	int			map_height;
	int			map_width;
	int			nb_players;
	int			nb_exit;
	int			nb_collectables;
	t_position	pos_p;
	t_position	pos_e;
	t_position	*pos_c;
	void		*mlx;
	void		*win;
	void		*img_super_kiwi;
	void		*img_lawn;
	void		*img_water;
	void		*img_kiwi_fruit;
	void		*img_box_closed;
	void		*img_box_open;
	bool		open_box;
}	t_game;

/* ************************************************************************** */
/*                                 PROTOTYPES                                 */
/* ************************************************************************** */

//map_read_and_load.c
int		map_loading(t_game *game, char *map_file);
int		load_line_to_map(t_game *game, char *line);
int		width_of_map(char *str);

//map_error_check.c
int		check_form(t_game *game);
int		check_walls(t_game *game);
int		check_e_p(t_game *game);
int		check_c(t_game *game);
int		check_map_errors(t_game *game);

//map_access_check.c
int		map_access_check(t_game *game);
void	flood_fill(t_game *game, t_position	starting_point, char target);

//parsing_utils.c
t_game	set_game_start(t_game *game);
void	assign_p_e(t_game *game, int y, int x, char c);
void	assign_c(t_game *game);
void	copy_map(t_game	*original_game, t_game *temp_game);
void	copy_pos_c(t_game	*original_game, t_game *temp_game);

// start_game.c
void	open_game(t_game *game);
void	upload_images(t_game *game);
void	render_map(t_game *game);
void	place_image(t_game *game, int y, int x);

//game_utils.c
int 	close_window(void *param);

//free_clear_and_close.c
void	close_temp_game(t_game *temp_game);
void	clear_game(t_game *game);
void	kill_game(t_game *game);
void	close_game(t_game *game, char *message);

//to delete
void	print_map(char **map, t_game *game);

#endif