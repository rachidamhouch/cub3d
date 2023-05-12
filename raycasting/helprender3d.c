/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helprender3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:48:24 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:51:09 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	*closedoor(void *ptr)
{
	t_cub3d	*cub3d;
	int		x;
	int		y;

	cub3d = (t_cub3d *)ptr;
	x = cub3d->draw.y;
	y = cub3d->draw.x;
	sleep(4);
	while (cub3d->map->square_map[cub3d->map->player.y / SIZE] \
		[cub3d->map->player.x / SIZE] == 'd')
	{
	}
	cub3d->map->square_map[x / SIZE][y / SIZE] = 'D';
	cub3d->events.closed = 1;
	system("afplay sounds/door.mp3&");
	return (0);
}

void	help_raycasting(t_cub3d *cub3d, int *i, float *start)
{
	float	a;
	float	b;

	if (*i == WIDTH / 2 && cub3d->draw.type == 'D' \
		&& cub3d->draw.distance < 150)
	{
		system("afplay sounds/door.mp3&");
		cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
			[(int)cub3d->draw.x / SIZE] = 'd';
		*start = cub3d->map->player.angle - 30;
		*i = 0;
		pthread_create(&cub3d->th, NULL, closedoor, cub3d);
		usleep(50);
	}
	a = ((float)SIZE / cub3d->draw.distance);
	b = ((WIDTH / 2) / tan((VEW_ANGLE / 2) * PI / 180));
	cub3d->draw.wall_height = a * b;
}

float	help_draw_wall(t_cub3d *cub3d, int *m, int *n, int *my)
{
	float	size;

	size = cub3d->draw.wall_height / SIZE;
	*m = 0;
	*n = 0;
	*my = 0;
	if (cub3d->draw.wall_height > HEIGHT)
		*my = (cub3d->draw.wall_height - HEIGHT) / 2;
	return (size);
}

int	help_draw_lined(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[(int)cub3d->draw.x / SIZE] == 'D')
	{
		cub3d->draw.type = 'D';
		return (1);
	}
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == 'D'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == 'D')
	{
		cub3d->draw.type = 'D';
		return (1);
	}
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == 'D'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == 'D')
	{
		cub3d->draw.type = 'D';
		return (1);
	}
	return (0);
}
