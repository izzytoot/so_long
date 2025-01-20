/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clear_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:19:38 by root              #+#    #+#             */
/*   Updated: 2025/01/20 15:45:51 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	clear_game(t_game *game)
{
	if (!game || !game->map)
		return ;
	free_map(game);
	game->map = NULL;
	if (game->pos_c)
	{
		free(game->pos_c);
		game->pos_c = NULL;
	}
}

void	close_temp_game(t_game *temp_game)
{
	if (!temp_game)
		return ;
	free_map(temp_game);
	temp_game->map = NULL;
	if (temp_game->pos_c)
	{
		free(temp_game->pos_c);
		temp_game->pos_c = NULL;
	}
	free(temp_game);
}

void	close_game(t_game *game, char *message)
{
	if (game->map)
		clear_game(game);
	if (message)
		ft_printf("%s\n", message);
	exit (0);
}
