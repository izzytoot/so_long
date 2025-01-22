/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:12:02 by root              #+#    #+#             */
/*   Updated: 2025/01/22 19:43:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	super_kiwi;

	if (ac != 2)
	{
		ft_printf(RED"To play game run: ./so_long <map_file>.\n"RESET);
		return (0);
	}
	super_kiwi = set_game_start(&super_kiwi);
	map_loading(&super_kiwi, av[1]);
	if (!check_map_errors(&super_kiwi))
		return (0);
	if (!map_access_check(&super_kiwi))
		return (0);
	super_kiwi.mlx = mlx_init();
	open_game(&super_kiwi);
	close_game(&super_kiwi, GREEN"The game was shut down!"RESET);
	return (0);
}
/*
função rato ?? + se sim, verificar numeros rato
verificar aumento de janela
mudar chão
caixa aberta/fechada
loop hook - preciso?
erros valgrind???
*/