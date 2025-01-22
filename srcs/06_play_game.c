/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_play_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:28:32 by root              #+#    #+#             */
/*   Updated: 2025/01/22 18:40:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int	key_controls(int keycode, t_game *game)
{
	int	move;
	
	if (keycode == KEY_ESC)
		close_game(game, YELLOW"Game window was closed!"RESET);
	if (keycode == KEY_W || keycode == KEY_UP || keycode == KEY_S || keycode == KEY_DOWN)
		move = vertical_moves(game, keycode);
	if (keycode == KEY_A || keycode == KEY_LEFT || keycode == KEY_D || keycode == KEY_RIGHT)
		move = horizontal_moves(game, keycode);
	if (move)
		render_map(game);
	return (0);
}

int	vertical_moves(t_game *game, int keycode)
{
	int	y;
	int	x;
	int	k;
	
	y = game->pos_player.y;
	x = game->pos_player.x;
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		k = move_player(game, y, x);
		if(!k)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{	
		y++;
		if (game->map[y][x] == '1')
			return (0);
		k = move_player(game, y, x);
		if(!k)
			return (0);
		game->map[y - 1][x] = '0';
	}
	return (1);
}

int		horizontal_moves(t_game *game, int keycode)
{
	int	y;
	int	x;
	int	k;
	
	y = game->pos_player.y;
	x = game->pos_player.x;
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		k = move_player(game, y, x);
		if(!k)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{	
		x++;
		if (game->map[y][x] == '1')
			return (0);
		k = move_player(game, y, x);
		if(!k)
			return (0);
		game->map[y][x - 1] = '0';
	}
	return (1);
}

int	move_player(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E')
	{
		if (game->nb_collectables != 0)
			return (0);
		close_game(game, GREEN"GAME FINISHED. SUCCESS!"RESET);
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
