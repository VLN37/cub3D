/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/26 19:28:11 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (validation(&data, argc, argv) == false)
		exit (EXIT_FAILURE);
	data.state = MENU;
	init_data(&data);
	replace_wall_next_door(&data);
	mlx_hook(data.mlx.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx.win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx.win, 4, 1L << 2, mouse_key_press, &data);
	mlx_hook(data.mlx.win, 5, 1L << 3, mouse_key_release, &data);
	mlx_hook(data.mlx.win, 6, 1L << 6, mouse_move, &data);
	mlx_hook(data.mlx.win, X_EVENT_DESTROY_NOTIFY, 0, &exit_x_notify, &data);
	mlx_loop_hook(data.mlx.mlx_ptr, &game_loop, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (0);
}
