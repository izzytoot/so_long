/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:49:37 by root              #+#    #+#             */
/*   Updated: 2025/01/16 19:39:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void free_map(t_game *game)
{
    int i;

	i = 0;
    while (i < game->map_height)
	{
        free(game->map[i]);
		i++;
	}
	free(game->map);
}

void print_map(char **map, t_game *game)
{
	int	i = 0;

	while (i < game->map_height)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

void	clear_game(t_game *game)
{
	if (!game || !game->map)
		return ;
	free_map(game);
	game->map = NULL;
}

void	close_game(t_game *game, char *message)
{
	if (game->map)
		clear_game(game);
	if (message)
		ft_printf("%s\n", message);
	exit (0);
}