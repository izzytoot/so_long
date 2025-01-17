/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:07:21 by root              #+#    #+#             */
/*   Updated: 2025/01/17 23:42:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	prep_chars(t_game	*game)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
				game->map[y][x] = '0';
			if (game->map[y][x] == 'E')
				game->map[y][x] = '0';
			if (game->map[y][x] == 'C')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, t_position	starting_point, char target)
{
	t_position	new_position;
	
	if (starting_point.x < 0 || starting_point.x >= game->map_width || starting_point.y < 0 || starting_point.y >= game->map_height)
		return ;
	if (game->map[starting_point.y][starting_point.x] == 'F' || game->map[starting_point.y][starting_point.x] != target)
		return ;
	game->map[starting_point.y][starting_point.x] = 'F';
	new_position = (t_position){starting_point.x + 1, starting_point.y};
	flood_fill(game, new_position, target);
	new_position = (t_position){starting_point.x - 1, starting_point.y};
	flood_fill(game, new_position, target);
	new_position = (t_position){starting_point.x, starting_point.y + 1};
	flood_fill(game, new_position, target);
	new_position = (t_position){starting_point.x, starting_point.y - 1};
	flood_fill(game, new_position, target);
}

int	check_route(t_game *game)
{
	t_position new_E;
	t_position new_C;
	int	c;
	
	new_E = (t_position){game->pos_E.y, game->pos_E.x};
	if (game->map[new_E.y][new_E.x] != 'F')
		return (0);
	c = 0;
	while(c < game->nb_collectables)
	{
		new_C = (t_position){game->pos_C[c].y, game->pos_C[c].x};
		if (game->map[new_C.y][new_C.x] != 'F')
			return (0);
		c++;
	}
	return (1);
}

void	map_access_check(t_game *game)
{
	t_game	*temp_game;
	int	size;
	
	if (!game)
		return ;
	size = game->map_height * game->map_width;
	temp_game = malloc(sizeof(t_position) * size);
	if(!temp_game)
		close_game(game, "\033[0;31mError: memory allocation failed.\033[0m");
	temp_game = game;
	temp_game->temp = true;
	prep_chars(temp_game);
	flood_fill(temp_game, temp_game->pos_P, '0');
	//print_map(game->map, game);
	if (!check_route(temp_game))
		close_game(game, "\033[0;31mError: inaccessible exit or collectable.\033[0m");
	close_game(temp_game, "");
}
/*
	memory issue - leaks + core dump with invalid maps
	check if pos_E and pos_c are filled
*/
