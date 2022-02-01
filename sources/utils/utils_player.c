/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/31 16:31:57 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player_matrix(t_data *data)
{
	t_xy	xy;
	int		player_x;
	int		player_y;

	xy = get_coordinates(data->map, 0, 0);
	player_x = data->player.x / TILE_SIZE;
	player_y = data->player.y / TILE_SIZE;
	if (xy.x != player_x || xy.y != player_y)
	{
		if (data->map[player_y][player_x] == '0')
		{
			data->map[xy.x][xy.y] = '0';
			data->map[player_y][player_x] = 'N';
			printf(CLEAR);
			print_colored_map(data->map);
			printf("player x %d player y %d\n", player_x, player_y);
			printf("xy.x %d xy.y %d\n", xy.x, xy.y);
		}
	}
}

void	update_player(t_data *data)
{
	float		move_step;
	float		new_player_x;
	float		new_player_y;
	t_player	*player;

	player = &data->player;
	player->rot_angle += player->turn_dir * player->turn_speed;
	normalize_angle(&player->rot_angle);
	move_step = player->walk_dir * player->walk_speed;
	new_player_x = player->x + cos(player->rot_angle) * move_step;
	new_player_y = player->y + sin(player->rot_angle) * move_step;
	if (!map_has_wall_at(new_player_x, new_player_y, data))
	{
		player->x = new_player_x;
		player->y = new_player_y;
	}
}