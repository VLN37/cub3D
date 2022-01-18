/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofelipe <jofelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:17:47 by jofelipe          #+#    #+#             */
/*   Updated: 2022/01/18 05:19:55 by jofelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (map[++i])
	{
		while (map[i][++j])
		{
			if (map[i][j] == '!')
				printf("%c", map[i][j]);
			else if (map[i][j] == ' ')
				printf("%c", ' ');
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
		j = -1;
	}
}

void	print_colored_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	// printf("\e[1;1H\e[2J");
	while (map[++i])
	{
		while (map[i][++j])
		{
			usleep(500);
			if (map[i][j] == '!')
				printf("\e[42m%c\e[0m", map[i][j]);
			else if (map[i][j] == '@')
				printf("\e[44m%c\e[0m", map[i][j]);
			else if (map[i][j] == ' ')
				printf("%c", ' ');
			else
				printf("\e[41m%c\e[0m", map[i][j]);
		}
		printf("\n");
		j = -1;
	}
}
