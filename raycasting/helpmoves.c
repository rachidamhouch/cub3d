/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpmoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:24:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:32:18 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	check_movements(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x) / SIZE][(y) / SIZE] == '1')
		return (2);
	return (0);
}

int	check_movements3(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == 'D' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == 'D')
		return (1);
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == 'D' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == 'D')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == 'D' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == 'D')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == 'D' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == 'D')
		return (1);
	if (cub3d->map->square_map[(x + 10) / SIZE][(y + 10) / SIZE] == 'D')
		return (2);
	if (cub3d->map->square_map[(x - 10) / SIZE][(y - 10) / SIZE] == 'D')
		return (2);
	return (0);
}

int	check_movements2(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x - 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y - 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 1) / SIZE][y / SIZE] == '1' &&
		cub3d->map->square_map[x / SIZE][(y + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[(x + 10) / SIZE][(y + 10) / SIZE] == '1')
		return (2);
	if (cub3d->map->square_map[(x - 10) / SIZE][(y - 10) / SIZE] == '1')
		return (2);
	return (check_movements3(cub3d, x, y));
}

int	is_wall(t_cub3d *cub3d, int x, int y)
{
	if (cub3d->map->square_map[y / SIZE][x / SIZE] == '1')
		return (1);
	return (0);
}

void	help_draw_line2(t_cub3d *cub3d, float angle)
{
	float	radians;
	int		steps;

	radians = angle * PI / 180;
	cub3d->draw.dx = 500 * cos(radians) * -1;
	cub3d->draw.dy = 500 * sin(radians);
	if (abs(cub3d->draw.dx) > abs(cub3d->draw.dy))
		steps = abs(cub3d->draw.dx);
	else
		steps = abs(cub3d->draw.dy);
	cub3d->draw.increment_x = cub3d->draw.dx / (float)steps;
	cub3d->draw.increment_y = cub3d->draw.dy / (float)steps;
	cub3d->draw.x = cub3d->map->player.x;
	cub3d->draw.y = cub3d->map->player.y;
}
