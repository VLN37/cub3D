/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/01/15 01:54:15 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_data(t_data *data, char **argv)
{
	(void)argv;
	data->mlx.mlx_ptr = mlx_init();
	data->mlx.win
		= mlx_new_window(data->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "cub3d");

	data->player.pos_x = 10.676025;
	data->player.pos_y = 18.382169;
	data->ray.dir_x = -1;
	data->ray.dir_y = 0;
	data->ray.plane_x = 0;
	data->ray.plane_y = 0.66;
	data->player.move_speed = 0.15;
	data->player.rot_speed = 0.05;

	init_img(data, &data->img[BG], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[SCREEN], IMG_WIDTH, IMG_HEIGHT);
	init_img(data, &data->img[RAYS], IMG_WIDTH, IMG_HEIGHT);

	// init_map(data, argv);

	init_xpm(data, &data->img[TEX_NO], TEXTURE1);
	init_xpm(data, &data->img[TEX_EA], TEXTURE3);
	init_xpm(data, &data->img[TEX_SO], TEXTURE2);
	init_xpm(data, &data->img[TEX_WE], TEXTURE4);
}
