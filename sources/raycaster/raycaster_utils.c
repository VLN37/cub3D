/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 13:10:51 by wleite            #+#    #+#             */
/*   Updated: 2022/01/30 00:42:27 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_ray_facing_down(float angle)
{
	return (angle > 0 && angle < PI);
}

int	is_ray_facing_up(float angle)
{
	return (!is_ray_facing_down(angle));
}

int	is_ray_facing_right(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

int	is_ray_facing_left(float angle)
{
	return (!is_ray_facing_right(angle));
}
