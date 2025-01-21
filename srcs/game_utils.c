/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icunha-t <icunha-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:52:35 by icunha-t          #+#    #+#             */
/*   Updated: 2025/01/21 13:48:19 by icunha-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int close_window(void *param)
{
    t_game *game = (t_game *)param;
    close_game(game, "The game has ended!");
    return (0);
}