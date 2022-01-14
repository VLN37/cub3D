/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/14 03:20:12 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");

	data->player.pos_x = 9.326093;
	data->player.pos_y = 18.390340;
	data->ray.dir_x = -1;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0.66;
	data->player.move_speed = 0.15;
	data->player.rot_speed = 0.05;

	init_img(data, &data->img[BG], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);

	init_xpm(data, &data->img[TEX_NO], TEXTURE1);
	init_xpm(data, &data->img[TEX_EA], TEXTURE3);
	init_xpm(data, &data->img[TEX_SO], TEXTURE2);
	init_xpm(data, &data->img[TEX_WE], TEXTURE4);
}
