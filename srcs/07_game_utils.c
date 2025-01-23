/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:35 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/23 16:11:38 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->map_height)
	{
		width = 0;
		while (width < game->map_width)
		{
			place_image(game, height, width);
			width++;
		}
		height++;
	}
}

int	key_controls(int keycode, t_game *game)
{
	int	move;

	if (keycode == KEY_ESC)
		close_game(game, YELLOW"Game window was closed!\n"RESET);
	if (keycode == KEY_W || keycode == KEY_UP)
		move = vertical_moves_up(game);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		move = vertical_moves_down(game);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		move = horizontal_moves_left(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		move = horizontal_moves_right(game);
	if (move)
		render_map(game);
	return (0);
}

void	getting_closer(t_game *game)
{
	game->nb_collectables--;
	if (game->nb_collectables > 1)
		ft_printf(YELLOW"Got it! %d kiwis to go.\n"RESET,
			game->nb_collectables);
	if (game->nb_collectables == 1)
		ft_printf(YELLOW"Got it! %d kiwi to go.\n"RESET,
			game->nb_collectables);
	if (game->nb_collectables < 1)
	{
		game->open_box = true;
		ft_printf(YELLOW"Good job, Super Kiwi. Now get to the box!\n"RESET);
	}
}

int	main_loop(t_game *game)
{
	user_controls(game);
	return (0);
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	close_game(game, YELLOW"The game has ended!\n"RESET);
	return (0);
}
