/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:28:32 by root              #+#    #+#             */
/*   Updated: 2025/01/23 15:59:24 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	vertical_moves_up(t_game *game)
{
	int	y;
	int	x;
	int	k;

	y = game->pos_player.y;
	x = game->pos_player.x;
	y--;
	if (game->map[y][x] == '1')
		return (0);
	k = move_player(game, y, x);
	if (!k)
		return (0);
	game->map[y + 1][x] = '0';
	return (1);
}

int	vertical_moves_down(t_game *game)
{
	int	y;
	int	x;
	int	k;

	y = game->pos_player.y;
	x = game->pos_player.x;
	y++;
	if (game->map[y][x] == '1')
		return (0);
	k = move_player(game, y, x);
	if (!k)
		return (0);
	game->map[y - 1][x] = '0';
	return (1);
}

int	horizontal_moves_left(t_game *game)
{
	int	y;
	int	x;
	int	k;

	y = game->pos_player.y;
	x = game->pos_player.x;
	x--;
	if (game->map[y][x] == '1')
		return (0);
	k = move_player(game, y, x);
	if (!k)
		return (0);
	game->map[y][x + 1] = '0';
	return (1);
}

int	horizontal_moves_right(t_game *game)
{
	int	y;
	int	x;
	int	k;

	y = game->pos_player.y;
	x = game->pos_player.x;
	x++;
	if (game->map[y][x] == '1')
		return (0);
	k = move_player(game, y, x);
	if (!k)
		return (0);
	game->map[y][x - 1] = '0';
	return (1);
}

int	move_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		if (game->nb_collectables != 0)
			return (0);
		close_game(game, GREEN"GAME FINISHED. SUCCESS!\n"RESET);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->pos_player.y = y;
		game->pos_player.x = x;
		game->nb_moves++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->pos_player.y = y;
		game->pos_player.x = x;
		getting_closer(game);
		game->nb_moves++;
	}
	ft_printf("Number of moves: %d\n", game->nb_moves);
	return (1);
}
