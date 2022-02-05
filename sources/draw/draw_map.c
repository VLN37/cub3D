/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 23:07:01 by wleite            #+#    #+#             */
/*   Updated: 2022/02/05 02:02:48 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static void	init_draw_map(t_data *data, int *height, int *len, t_xy *pl)
{
	t_fill	vars;

	*height = get_height(data->map);
	*len = ft_strlen(data->map[0]);
	*pl = get_coordinates(data->map, 0, 0);
	vars = fillparams(502, 55, 10 * 23, 10 * 23);
	fill(&data->img[MAP], vars, BLACKB);
}

void	draw_map(t_data *data, char **map, int x, int y)
{
	t_xy	pl;
	t_fill	vars;
	int		len;
	int		height;

	init_draw_map(data, &height, &len, &pl);
	while (++x < 21)
	{
		while (++y < 21)
		{
			vars = fillparams(WIN_HEIGHT - 270 + 11 * x, 50 + 11 * y, 10, 10);
			if (pl.x + x - 10 < 0 || pl.y + y - 10 < 0
				|| pl.x + x - 9 > height || pl.y + y - 9 > len)
				fill(&data->img[MAP], vars, 0x5c5c5c);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "@! "))
				fill(&data->img[MAP], vars, 0x1b4382);
			else if (ftex_is_in_set(map[pl.x + x - 10][pl.y + y - 10], "NSEW"))
				fill(&data->img[MAP], vars, YELLOW);
			else
				fill(&data->img[MAP], vars, 0x5c5c5c);
		}
		y = -1;
	}
}
