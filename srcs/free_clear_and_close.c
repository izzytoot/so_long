/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_clear_and_close.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:19:38 by root              #+#    #+#             */
/*   Updated: 2025/01/17 18:58:58 by root             ###   ########.fr       */
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

void	clear_game(t_game *game)
{
	if (!game || !game->map)
		return ;
	free(game->pos_C);
	game->pos_C = NULL;
	free_map(game);
	game->map = NULL;
}

void	close_game(t_game *game, char *message)
{
	if (game->map)
		clear_game(game);
	if (message && game->temp == false)
		ft_printf("%s\n", message);
	exit (0);
}
