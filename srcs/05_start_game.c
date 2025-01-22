/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:33:12 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/22 19:43:29 by root             ###   ########.fr       */
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
	user_controls(game);
//	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}

void	upload_images(t_game *game)
{
	int	img_x;
	int	img_y;

	img_x = TILE_SIZE;
	img_y = TILE_SIZE;
	game->img = malloc(sizeof(t_images));
	if (!game->img)
    	close_game(game, "Failed to allocate memory for images.");
	game->img->super_kiwi = mlx_xpm_file_to_image(game->mlx, "./images/super_kiwi.xpm", &img_x, &img_y);
	game->img->lawn = mlx_xpm_file_to_image(game->mlx, "./images/lawn.xpm", &img_x, &img_y);
	game->img->water = mlx_xpm_file_to_image(game->mlx, "./images/water.xpm", &img_x, &img_y);
	game->img->kiwi_fruit = mlx_xpm_file_to_image(game->mlx, "./images/kiwi_fruit.xpm", &img_x, &img_y);
	game->img->box_closed = mlx_xpm_file_to_image(game->mlx, "./images/box_closed.xpm", &img_x, &img_y);
	game->img->box_open = mlx_xpm_file_to_image(game->mlx, "./images/box_open.xpm", &img_x, &img_y);
	if (!game->img->super_kiwi || !game->img->lawn || !game->img->water ||
			!game->img->kiwi_fruit || !game->img->box_closed || !game->img->box_open)
		close_game(game, "Failed to upload image.");
}

void	place_image(t_game *game, int y, int x)
{
	if(game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->water, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img->lawn, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img->super_kiwi, x * TILE_SIZE, y * TILE_SIZE);
		game->pos_player.y = y;
		game->pos_player.x = x;
	}
	else if(game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img->kiwi_fruit, x * TILE_SIZE, y * TILE_SIZE);
	else if(game->map[y][x] == 'E')
	{
		if(game->open_box == false)
			mlx_put_image_to_window(game->mlx, game->win, game->img->box_closed, x * TILE_SIZE, y * TILE_SIZE);
		if(game->open_box == true)
			mlx_put_image_to_window(game->mlx, game->win, game->img->box_open, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	user_controls(t_game *game)
{
	mlx_key_hook(game->win, key_controls, game);
	mlx_hook(game->win,  4, 1L << 2, mouse_control, game);
}