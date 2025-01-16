/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:32 by root              #+#    #+#             */
/*   Updated: 2025/01/16 19:51:41 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_form(t_game *game)
{
	int	i;
	size_t	row_size;
	
	if (!game || !game->map)
		return (0);
	i = 0;
	row_size = game->map_width;
	while(i < game->map_height - 1)
	{
		ft_printf("length of row %d is %d\n", i, ft_strlen(game->map[i]));
		if (ft_strlen(game->map[i]) != row_size)
			return (0);
		i++;
	}
	return (1);
}
/*
static int	check_walls(t_game *game)
{
	limits have to be 1s
	
	return (0);
}

static int	check_E_and_P(t_game *game)
{
	1 E and 1 P
	
	return (0);
}

static int	check_collectables(t_game	*game)
{
	at least 1 collectable
	
	return (0);
}
*/
void	check_map_errors(t_game *game)
{
	if (!game)
		close_game(game, "\033[0;31mError: no game found.\n\033[0m");
	if (!game->map)
		close_game(game, "\033[0;31mError: no map found.\n\033[0m");
	if (!check_form(game))
		close_game(game, "\033[0;31mError: map format is incorrect.\n\033[0m");
	/*
	if (!check_walls)
		close_game(game, "\033[0;31mError: wall is missing.\n\033[0m");
	if (!check_E_and_P)
		close_game(game, "\033[0;31mError: exit or stating position are incorrect.\n\033[0m");
	if (!check_collectables)
		close_game(game, "\033[0;31mError: collectables are incorrect.\n\033[0m");
	*/
}

