/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clear_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:19:38 by root              #+#    #+#             */
/*   Updated: 2025/01/21 17:31:39 by icunha-t         ###   ########.fr       */
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
		if (game->map)
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		i++;
	}
	if (game->map)
		free(game->map);
	game->map = NULL;
	if (game->pos_c)
	{
		free(game->pos_c);
		game->pos_c = NULL;
	}
}

void	kill_game(t_game *game)
{
	if (!game)
        return;
	if (game->img_super_kiwi)
		mlx_destroy_image(game->mlx, game->img_super_kiwi);
	if (game->img_water)
		mlx_destroy_image(game->mlx, game->img_water);
	if (game->img_lawn)
		mlx_destroy_image(game->mlx, game->img_lawn);
	if (game->img_kiwi_fruit)
		mlx_destroy_image(game->mlx, game->img_kiwi_fruit);
	if (game->img_box_closed)
		mlx_destroy_image(game->mlx, game->img_box_closed);
	if (game->img_box_open)
		mlx_destroy_image(game->mlx, game->img_box_open);
	if (game->win)
	{	
		mlx_destroy_image(game->mlx, game->win);
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
	clear_game(game);
	kill_game(game);
	if (message)
		ft_printf("%s\n", message);
	exit (0);
}
