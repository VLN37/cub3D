/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/15 00:25:38 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	middle_x(t_img img)
{
	return (WIN_WIDTH / 2 - (img.width / 2));
}

int	middle_y(t_img img)
{
	return (WIN_HEIGHT / 2 - (img.height / 2));
}

void	fill_menu_item(t_data *data, int i, int offy, int offx)
{
	while (i--)
		put_menu_item(data, BLOCK, offy - (100 * i) + 100, offx);
}

void	put_menu_item(t_data *data, int src, int offy, int offx)
{
	t_menu_elem	elem;

	elem.dst = &data->img[SCREEN];
	elem.src = &data->img[src];
	elem.x = middle_x(data->img[src]) - offy;
	elem.y = middle_y(data->img[src]) + offx;
	copy_layer(elem.src, elem.dst, elem.x, elem.y);
}
