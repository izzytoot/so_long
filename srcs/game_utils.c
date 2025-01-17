/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:49:37 by root              #+#    #+#             */
/*   Updated: 2025/01/17 23:40:32 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_game	set_game_start(t_game *game)
{
	game->fd = 0;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->nb_players = 0;
	game->nb_exit = 0;
	game->nb_collectables = 0;
	game->pos_P.y = 0;
	game->pos_P.x = 0;
	game->pos_E.y = 0;
	game->pos_E.x = 0;
	game->temp = false;
	return(*game);
}

void	assign_pos_P_E(t_game *game, int y, int x, char c)
{
	t_position	position;
	
	position.y = x;
	position.x = y;
	if (c == 'P')	
		game->pos_P = position;
	if (c == 'E')
		game->pos_E = position;
}

void	assign_pos_C(t_game *game)
{
	int x;
	int	y;
	int	i;
	
	game->pos_C = malloc(sizeof(t_position) * game->nb_collectables);
	i = 0;
	if (!game->pos_C)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				game->pos_C[i].x = x;
				game->pos_C[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void print_map(char **map, t_game *game)
{
	int	i = 0;

	while (i < game->map_height)
	{
		ft_printf("%s", map[i]);
		if (i != game->map_height)
			ft_printf("\n");
		i++;
	}
}