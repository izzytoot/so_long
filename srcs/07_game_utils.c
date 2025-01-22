/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_game_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:35 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/22 19:36:57 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while(height < game->map_height)
	{
		width = 0;
		while(width < game->map_width)
		{
			place_image(game, height, width);
			width++;
		}
		height++;
	}
}

int	mouse_control(int keycode, t_game *game)
{
	(void)game;

	if (keycode == 1)
		ft_printf("left mouse button clicked\n");
	if (keycode == 2)
		ft_printf("right mouse button clicked\n");
	if (keycode == 3)
		ft_printf("middle mouse button clicked\n");
	if (keycode == 4)
		ft_printf("scrolled up with mouse\n");
	if (keycode == 5)
		ft_printf("scrolled down with mouse\n");
	return (0);
}

void	getting_closer(t_game *game)
{
	game->nb_collectables--;
	if (game->nb_collectables > 1)
		ft_printf(YELLOW"Got it! %d kiwis to go.\n"RESET, game->nb_collectables);
	if (game->nb_collectables == 1)
		ft_printf(YELLOW"Got it! %d kiwi to go.\n"RESET, game->nb_collectables);
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

int close_window(void *param)
{
    t_game *game = (t_game *)param;
    close_game(game, YELLOW"The game has ended!"RESET);
    return (0);
}
