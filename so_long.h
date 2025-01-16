/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:27 by root              #+#    #+#             */
/*   Updated: 2025/01/16 19:15:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"


# include <stdlib.h>
# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>
# include "libft/libft.h"

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
	int		fd;
	char	**map;
	int		map_height;
	int		map_width;
}	t_game;

/* ************************************************************************** */
/*                                 PROTOTYPES                                 */
/* ************************************************************************** */

//map_read_and_load.c
int	map_loading(t_game *game, char *map_file);
int	load_line_to_map(t_game *game, char *line);
int	width_of_map(char *str);

//map_parsing.c
void	check_map_errors(t_game *game);

//map_utils.c
void free_map(t_game *game);
void print_map(char **map, t_game *game);
void	clear_game(t_game *game);
void	close_game(t_game *game, char *message);

#endif