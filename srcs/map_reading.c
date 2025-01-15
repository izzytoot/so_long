/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:32 by root              #+#    #+#             */
/*   Updated: 2025/01/15 19:21:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	width_of_map(char *str)
{
	int	width;

	width = 0;
	while (str[width])
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

static int	new_line(t_game *game, char *line)
{
	char **temp;
	int	i;

	if(!line)
		return (0);
	i = 0;
	game->map_height++;
	temp = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	while (i < game->map_height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	*temp[i] = line;
	if (game->map)
		free(game->map);
	game->map = temp;
	return (1);
}

int	map_reading(t_game *game, char *map_file)
{
	char *readmap;
	
	game->fd = open(map_file, O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		readmap = get_next_line(game->fd);
		if(!new_line(game, &readmap))
			break;
	}
	close(game->fd);
	game->map_width = width_of_map(game->map[0]);
	return (1);
}