/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 19:36:18 by wleite            #+#    #+#             */
/*   Updated: 2022/02/20 01:12:15 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	game_loop(t_data *data)
{
	if (data->state == MENU)
		draw_menu(data);
	if (data->state == GAME)
	{
		update_player(data);
		update_player_matrix(data);
		update_sprites(data);
		update_animations(data);
		cast_all_rays(data);
		draw_game(data);
	}
	if (data->state == OPTIONS)
		draw_options(data);
	sync_time(data);
	return (0);
}
