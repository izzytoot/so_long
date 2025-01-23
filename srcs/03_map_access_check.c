/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_map_access_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:07:21 by root              #+#    #+#             */
/*   Updated: 2025/01/23 15:59:03 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	prep_chars(t_game *game)
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
			if (game->map[y][x] == 'C')
				game->map[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, t_position	start_p, char target)
{
	t_position	new_position;

	if (start_p.x < 0 || start_p.x >= game->map_width
		|| start_p.y < 0 || start_p.y >= game->map_height)
		return ;
	if (game->map[start_p.y][start_p.x] == 'F'
		|| game->map[start_p.y][start_p.x]
		!= target || game->map[start_p.y][start_p.x] == 'E')
	{
		if (game->map[start_p.y][start_p.x] == 'E')
		{
			game->exit_access = true;
		}
		return ;
	}
	game->map[start_p.y][start_p.x] = 'F';
	new_position = (t_position){start_p.x + 1, start_p.y};
	flood_fill(game, new_position, target);
	new_position = (t_position){start_p.x - 1, start_p.y};
	flood_fill(game, new_position, target);
	new_position = (t_position){start_p.x, start_p.y + 1};
	flood_fill(game, new_position, target);
	new_position = (t_position){start_p.x, start_p.y - 1};
	flood_fill(game, new_position, target);
}

int	check_route(t_game *game)
{
	int			c;

	if (!game->exit_access)
		return (0);
	c = 0;
	while (c < game->nb_collectables)
	{
		if (game->map[game->pos_c[c].y][game->pos_c[c].x] != 'F')
			return (0);
		c++;
	}
	return (1);
}

int	map_access_check(t_game *game)
{
	t_game	*temp_game;

	if (!game)
		return (0);
	temp_game = malloc(sizeof(t_game));
	if (!temp_game)
	{
		close_temp_game(temp_game);
		return (0);
	}
	*temp_game = *game;
	copy_map(game, temp_game);
	if (game->pos_c)
		copy_pos_c(game, temp_game);
	prep_chars(temp_game);
	flood_fill(temp_game, temp_game->pos_p, '0');
	if (!check_route(temp_game))
	{
		close_temp_game(temp_game);
		close_game(game, RED"Error: no access to Exit or Collectable.\n"RESET);
		return (0);
	}
	close_temp_game(temp_game);
	return (1);
}
