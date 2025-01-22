/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:32 by root              #+#    #+#             */
/*   Updated: 2025/01/22 11:30:18 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_form(t_game *game)
{
	int		i;
	size_t	row_size;

	if (!game || !game->map)
		return (0);
	i = 0;
	row_size = game->map_width;
	while (i < game->map_height - 1)
	{
		if (ft_strlen(game->map[i]) != row_size)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_width)
	{
		if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_e_p(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (++y < game->map_height)
	{
		x = 0;
		while (++x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->nb_players++;
				assign_p_e(game, y, x, 'P');
			}
			if (game->map[y][x] == 'E')
			{
				game->nb_exit++;
				assign_p_e(game, y, x, 'E');
			}
		}
	}
	if (game->nb_players != 1 || game->nb_exit != 1)
		return (0);
	return (1);
}

int	check_c(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
				game->nb_collectables++;
			x++;
		}
		y++;
	}
	if (game->nb_collectables < 1)
		return (0);
	assign_c(game);
	return (1);
}

int	check_map_errors(t_game *game)
{
	if (!game || !game->map)
		close_game(game, RED"Error: game or map not found."RESET);
	if (!check_form(game))
		close_game(game, RED"Error: map format is incorrect."RESET);
	if (!check_walls(game))
		close_game(game, RED"Error: wall is missing."RESET);
	if (!check_e_p(game))
		close_game(game, RED"Error: incorret number of exits or players."RESET);
	if (!check_c(game))
		close_game(game, RED"Error: not enough collectables."RESET);
	return (1);
}
