/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_free_clear_and_close.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:19:38 by root              #+#    #+#             */
/*   Updated: 2025/01/23 19:18:49 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_temp_game(t_game *temp_game)
{
	int	i;

	if (!temp_game)
		return ;
	i = 0;
	while (i < temp_game->map_height)
	{
		if (temp_game->map && temp_game->map[i])
		{
			free(temp_game->map[i]);
			temp_game->map[i] = NULL;
		}
		i++;
	}
	if (temp_game->map)
		free(temp_game->map);
	temp_game->map = NULL;
	if (temp_game->pos_c)
	{
		free(temp_game->pos_c);
		temp_game->pos_c = NULL;
	}
	if (temp_game->img)
		free(temp_game->img);
	free(temp_game);
}

void	clear_game(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	free(game->map);
	game->map = NULL;
	if (game->pos_c)
		free(game->pos_c);
	game->pos_c = NULL;
	if (game->img)
		free(game->img);
	game->img = NULL;
}

void	kill_game_visuals(t_game *game)
{
	if (!game)
		return ;
	if (game->img->super_kiwi)
		mlx_destroy_image(game->mlx, game->img->super_kiwi);
	if (game->img->water)
		mlx_destroy_image(game->mlx, game->img->water);
	if (game->img->tile)
		mlx_destroy_image(game->mlx, game->img->tile);
	if (game->img->kiwi_fruit)
		mlx_destroy_image(game->mlx, game->img->kiwi_fruit);
	if (game->img->box_closed)
		mlx_destroy_image(game->mlx, game->img->box_closed);
	if (game->img->box_open)
		mlx_destroy_image(game->mlx, game->img->box_open);
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	close_game(t_game *game, char *message)
{
	if (!game)
		return ;
	if (game->start)
		kill_game_visuals(game);
	clear_game(game);
	if (message)
		ft_putstr_fd(message, 2);
	exit (0);
}
