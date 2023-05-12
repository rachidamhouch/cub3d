/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 00:33:10 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:50:29 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	key_hook(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
	{
		cub3d->map->player.angle += RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == LEFT_ROW)
	{
		cub3d->map->player.angle -= RET_ANGLE;
		render_map(cub3d, 0, 0, 0);
	}
	else if (keycode == RIGHT_MOVE)
		right(cub3d, 0, 0);
	else if (keycode == LEFT_MOVE)
		left(cub3d, 0, 0);
	else if (keycode == DOWN_MOVE)
		down(cub3d, 0, 0);
	else if (keycode == UP_MOVE)
		up(cub3d, 0, 0);
	if (keycode == ESC)
		close_window2d(cub3d);
	return (0);
}

int	press(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
		cub3d->events.right_row = 1;
	else if (keycode == LEFT_ROW)
		cub3d->events.left_row = 1;
	else if (keycode == RIGHT_MOVE)
		cub3d->events.right_move = 1;
	else if (keycode == LEFT_MOVE)
		cub3d->events.left_move = 1;
	else if (keycode == DOWN_MOVE)
		cub3d->events.down_move = 1;
	else if (keycode == UP_MOVE)
		cub3d->events.up_move = 1;
	if (keycode == ESC)
		cub3d->events.esc = 1;
	return (0);
}

int	depress(int keycode, t_cub3d *cub3d)
{
	if (keycode == RIGHT_ROW)
		cub3d->events.right_row = 0;
	else if (keycode == LEFT_ROW)
		cub3d->events.left_row = 0;
	else if (keycode == RIGHT_MOVE)
		cub3d->events.right_move = 0;
	else if (keycode == LEFT_MOVE)
		cub3d->events.left_move = 0;
	else if (keycode == DOWN_MOVE)
		cub3d->events.down_move = 0;
	else if (keycode == UP_MOVE)
		cub3d->events.up_move = 0;
	if (keycode == ESC)
		cub3d->events.esc = 0;
	if (keycode == MAP)
	{
		system("afplay sounds/popup.mp3&");
		if (!cub3d->mmap)
			cub3d->mmap = 1;
		else
			cub3d->mmap = 0;
		cub3d->events.map = 1;
	}
	return (0);
}

void	*animate(void *ptr)
{
	t_cub3d	*cub3d;

	cub3d = (t_cub3d *)ptr;
	cub3d->gun.img = cub3d->gun.g0;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g1;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g2;
	usleep(100000);
	system("afplay sounds/gun.mp3&");
	cub3d->gun.img = cub3d->gun.g3;
	usleep(50000);
	cub3d->gun.img = cub3d->gun.g4;
	usleep(100000);
	cub3d->gun.img = cub3d->gun.g5;
	usleep(100000);
	cub3d->gun.img = cub3d->gun.g0;
	return (0);
}

void	shoot(t_cub3d *cub3d)
{
	pthread_t	th;

	pthread_create(&th, NULL, animate, cub3d);
}
