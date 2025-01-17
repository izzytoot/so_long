/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:32 by root              #+#    #+#             */
/*   Updated: 2025/01/17 20:40:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_form(t_game *game)
{
	int	i;
	size_t	row_size;
	
	if (!game || !game->map)
		return (0);
	i = 0;
	row_size = game->map_width;
	while(i < game->map_height - 1)
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

int	check_E_P(t_game *game)
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
				assign_pos_P_E(game, y, x, 'P');
			}
			if (game->map[y][x] == 'E')
			{
				game->nb_exit++;
				assign_pos_P_E(game, y, x, 'E');
			}
		}
	}
	if (game->nb_players != 1 || game->nb_exit != 1)
		return (0);	
	return (1);
}

int	check_C(t_game *game)
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
	assign_pos_C(game);
	return (1);
}

void	check_map_errors(t_game *game)
{
	if (!game)
		close_game(game, "\033[0;31mError: no game found.\033[0m");
	if (!game->map)
		close_game(game, "\033[0;31mError: no map found.\033[0m");
	if (!check_form(game))
		close_game(game, "\033[0;31mError: map format is incorrect.\033[0m");
	if (!check_walls(game))
			close_game(game, "\033[0;31mError: wall is missing.\033[0m");
	if (!check_E_P(game))
		close_game(game, "\033[0;31mError: incorrect number of exits or starting positions.\033[0m");
	if (!check_C(game))
		close_game(game, "\033[0;31mError: incorrect number of colectables.\033[0m");
}

