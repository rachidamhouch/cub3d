/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 23:16:13 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:35:24 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	help_movements(float angle, t_cub3d *cub3d)
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

void	up(t_cub3d *cub3d, int x, int y)
{
	int		i;

	i = 0;
	help_movements(cub3d->map->player.angle, cub3d);
	while (i++ < SPEED)
	{
		x = cub3d->draw.x;
		y = cub3d->draw.y;
		cub3d->draw.x -= cub3d->draw.increment_x;
		cub3d->draw.y -= cub3d->draw.increment_y;
		if (check_movements(cub3d, cub3d->draw.y, cub3d->draw.x))
		{
			if (!check_movements(cub3d, cub3d->draw.y, x))
				cub3d->draw.x = x;
			else if (!check_movements(cub3d, y, cub3d->draw.x))
				cub3d->draw.y = y;
			else
				break ;
		}
		cub3d->map->player.x = cub3d->draw.x;
		cub3d->map->player.y = cub3d->draw.y;
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
}

void	down(t_cub3d *cub3d, int x, int y)
{
	int		i;

	i = 0;
	help_movements(cub3d->map->player.angle, cub3d);
	while (i++ < SPEED)
	{
		x = cub3d->draw.x;
		y = cub3d->draw.y;
		cub3d->draw.x += cub3d->draw.increment_x;
		cub3d->draw.y += cub3d->draw.increment_y;
		if (check_movements(cub3d, cub3d->draw.y, cub3d->draw.x))
		{
			if (!check_movements(cub3d, cub3d->draw.y, x))
				cub3d->draw.x = x;
			else if (!check_movements(cub3d, y, cub3d->draw.x))
				cub3d->draw.y = y;
			else
				break ;
		}
		cub3d->map->player.x = cub3d->draw.x;
		cub3d->map->player.y = cub3d->draw.y;
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
}

void	left(t_cub3d *cub3d, int x, int y)
{
	int		i;

	i = 0;
	help_movements(cub3d->map->player.angle + 90, cub3d);
	while (i++ < SPEED)
	{
		x = cub3d->draw.x;
		y = cub3d->draw.y;
		cub3d->draw.x += cub3d->draw.increment_x;
		cub3d->draw.y += cub3d->draw.increment_y;
		if (check_movements(cub3d, cub3d->draw.y, cub3d->draw.x))
		{
			if (!check_movements(cub3d, cub3d->draw.y, x))
				cub3d->draw.x = x;
			else if (!check_movements(cub3d, y, cub3d->draw.x))
				cub3d->draw.y = y;
			else
				break ;
		}
		cub3d->map->player.x = cub3d->draw.x;
		cub3d->map->player.y = cub3d->draw.y;
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
}

void	right(t_cub3d *cub3d, int x, int y)
{
	int		i;

	i = 0;
	help_movements(cub3d->map->player.angle - 90, cub3d);
	while (i++ < SPEED)
	{
		x = cub3d->draw.x;
		y = cub3d->draw.y;
		cub3d->draw.x += cub3d->draw.increment_x;
		cub3d->draw.y += cub3d->draw.increment_y;
		if (check_movements(cub3d, cub3d->draw.y, cub3d->draw.x))
		{
			if (!check_movements(cub3d, cub3d->draw.y, x))
				cub3d->draw.x = x;
			else if (!check_movements(cub3d, y, cub3d->draw.x))
				cub3d->draw.y = y;
			else
				break ;
		}
		cub3d->map->player.x = cub3d->draw.x;
		cub3d->map->player.y = cub3d->draw.y;
	}
	if (i > 1)
		render_map(cub3d, 0, 0, 0);
}
