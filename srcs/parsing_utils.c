/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:49:37 by root              #+#    #+#             */
/*   Updated: 2025/01/20 16:10:10 by icunha-t         ###   ########.fr       */
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
	game->pos_p.y = 0;
	game->pos_p.x = 0;
	game->pos_e.y = 0;
	game->pos_e.x = 0;
	game->pos_c = NULL;
	return (*game);
}

void	assign_p_e(t_game *game, int y, int x, char c)
{
	t_position	position;

	position.y = x;
	position.x = y;
	if (c == 'P')
		game->pos_p = position;
	if (c == 'E')
		game->pos_e = position;
}

void	assign_c(t_game *game)
{
	int	x;
	int	y;
	int	i;

	game->pos_c = malloc(sizeof(t_position) * game->nb_collectables);
	i = 0;
	if (!game->pos_c)
		return ;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'C')
			{
				game->pos_c[i].x = x;
				game->pos_c[i].y = y;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	copy_map(t_game	*original_game, t_game *temp_game)
{
	int	i;

	i = 0;
	temp_game->map = malloc(sizeof(char *) * original_game->map_height);
	if (!temp_game->map)
	{
		clear_game(temp_game);
		return ;
	}
	i = 0;
	while (i < original_game->map_height)
	{
		temp_game->map[i] = malloc(sizeof(char)
				* (original_game->map_width + 1));
		if (!temp_game->map[i])
		{
			clear_game(temp_game);
			return ;
		}
		ft_strlcpy(temp_game->map[i], original_game->map[i],
			original_game->map_width + 1);
		i++;
	}
}

void	copy_pos_c(t_game	*original_game, t_game *temp_game)
{
	int	i;

	i = 0;
	temp_game->pos_c = malloc(sizeof(char *) * original_game->nb_collectables);
	if (!temp_game->pos_c)
	{
		clear_game(temp_game);
		return ;
	}
	i = 0;
	while (i < original_game->nb_collectables)
	{
		temp_game->pos_c[i].y = original_game->pos_c[i].y;
		temp_game->pos_c[i].x = original_game->pos_c[i].x;
		i++;
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
