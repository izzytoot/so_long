/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:02 by root              #+#    #+#             */
/*   Updated: 2025/01/20 16:43:37 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	super_kiwi;

	if (ac != 2)
	{
		ft_printf("\033[0;31mNo map added. Run: ./so_long <map_file>\n\033[0m");
		return (0);
	}
	super_kiwi = set_game_start(&super_kiwi);
	map_loading(&super_kiwi, av[1]);
	if (!check_map_errors(&super_kiwi))
		return (0);
	if (!map_access_check(&super_kiwi))
		return (0);
	open_window(&super_kiwi);
	close_game(&super_kiwi, "The game has ended!");
	return (0);
}
/*
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 5, 5);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);

joao:
	load_images(&game);
	start_window(&game);
	render_map(&game);

*/
