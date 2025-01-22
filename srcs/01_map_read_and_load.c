/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_and_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:04:32 by root              #+#    #+#             */
/*   Updated: 2025/01/22 11:31:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	width_of_map(char *str)
{
	int	width;

	width = 0;
	while (str[width])
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

int	load_line_to_map(t_game *game, char *line)
{
	char	**temp;
	size_t	len;
	int		i;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	i = 0;
	temp = malloc(sizeof(char *) * (game->map_height + 2));
	if (!temp)
		return (0);
	while (i < game->map_height)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[game->map_height] = line;
	temp[game->map_height + 1] = NULL;
	if (game->map)
		free(game->map);
	game->map = temp;
	game->map_height++;
	return (1);
}

int	map_loading(t_game *game, char *map_file)
{
	char	*read_line;

	game->fd = open(map_file, O_RDONLY);
	if (game->fd < 0)
		return (0);
	game->map = NULL;
	game->map_height = 0;
	while (1)
	{
		read_line = get_next_line(game->fd);
		if (!read_line)
			break ;
		if (!load_line_to_map(game, read_line))
		{
			free(read_line);
			break ;
		}
	}
	close(game->fd);
	if (game->map && game->map[0])
		game->map_width = width_of_map(game->map[0]);
	else
		game->map_width = 0;
	return (1);
}
