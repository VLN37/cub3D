/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_wasd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:22:26 by jofelipe          #+#    #+#             */
/*   Updated: 2022/02/14 23:28:39 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	keys_press_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.walk_dir = 1;
	if (key == KEY_A)
		data->player.side_dir = 1;
	if (key == KEY_S)
		data->player.walk_dir = -1;
	if (key == KEY_D)
		data->player.side_dir = -1;
	if (key == KEY_A_LEFT)
		data->player.turn_dir = -1;
	if (key == KEY_A_RIGHT)
		data->player.turn_dir = 1;
	if (key == KEY_A_UP)
		data->player.look_dir = 1;
	if (key == KEY_A_DOWN)
		data->player.look_dir = -1;
}

static void	keys_release_wasd(int key, t_data *data)
{
	if (key == KEY_W)
		data->player.walk_dir = 0;
	if (key == KEY_A)
		data->player.side_dir = 0;
	if (key == KEY_S)
		data->player.walk_dir = 0;
	if (key == KEY_D)
		data->player.side_dir = 0;
	if (key == KEY_A_LEFT)
		data->player.turn_dir = 0;
	if (key == KEY_A_RIGHT)
		data->player.turn_dir = 0;
	if (key == KEY_A_UP)
		data->player.look_dir = 0;
	if (key == KEY_A_DOWN)
		data->player.look_dir = 0;
}

void	keys_wasd(int key, t_data *data, int event_type)
{
	if (event_type == K_PRESS)
		keys_press_wasd(key, data);
	if (event_type == K_RELEASE)
		keys_release_wasd(key, data);
}
