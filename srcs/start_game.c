/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:33:12 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/21 17:36:56 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->map_width * 32, game->map_height * 32, "Super Kiwi");
	if (!game->win)
		close_game(game, "Failed to open window.");
	upload_images(game);
	render_map(game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}

void	upload_images(t_game *game)
{
	int	img_width;
	int	img_height;

	img_width = TILE_SIZE;
	img_height = TILE_SIZE;
	game->img_super_kiwi = mlx_xpm_file_to_image(game->mlx, "./images/super_kiwi.xpm", &img_width, &img_height);
	game->img_lawn = mlx_xpm_file_to_image(game->mlx, "./images/lawn.xpm", &img_width, &img_height);
	game->img_water = mlx_xpm_file_to_image(game->mlx, "./images/water.xpm", &img_width, &img_height);
	game->img_kiwi_fruit = mlx_xpm_file_to_image(game->mlx, "./images/kiwi_fruit.xpm", &img_width, &img_height);
	game->img_box_closed = mlx_xpm_file_to_image(game->mlx, "./images/box_closed.xpm", &img_width, &img_height);
	game->img_box_open = mlx_xpm_file_to_image(game->mlx, "./images/box_open.xpm", &img_width, &img_height);
	if (!game->img_super_kiwi || !game->img_lawn || !game->img_water ||
			!game->img_kiwi_fruit || !game->img_box_closed || !game->img_box_open)
		close_game(game, "Failed to upload image.");
}

void	render_map(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while(height < game->map_height)
	{
		width = 0;
		while(width < game->map_width)
		{
			place_image(game, height, width);
			width++;
		}
		height++;
	}
}
void	place_image(t_game *game, int y, int x)
{
	if(game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_water, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_lawn, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_super_kiwi, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_kiwi_fruit, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == 'E')
	{	
		mlx_put_image_to_window(game->mlx, game->win, game->img_box_closed, x * TILE_SIZE, y * TILE_SIZE);
		if(game->open_box)
			mlx_put_image_to_window(game->mlx, game->win, game->img_box_open, TILE_SIZE, TILE_SIZE);
	}
}
