/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:02 by root              #+#    #+#             */
/*   Updated: 2025/01/15 19:18:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	super_kiwi;
	
	if (ac != 2)
		ft_printf("\033[0;31mNo map added. Please run program with map: ./so_long <map_file>\n\033[0m");
	map_reading(&super_kiwi, av[1]);
}
/*
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	img.img = mlx_new_image(mlx, 5, 5);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len, &img.endian);
	mlx_pixel_put(mlx, mlx_win, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 200);
	mlx_loop(mlx);
*/

