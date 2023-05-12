/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:49:49 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:37:14 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	help_action(t_cub3d *cub3d, int i)
{
	if (cub3d->events.shoot2 && i++)
		cub3d->events.shoot2 = 0;
	if (cub3d->events.closed && i++)
		cub3d->events.closed = 0;
	if (cub3d->events.start == 1)
	{
		cub3d->events.start = 2;
		raycasting(cub3d, 0);
	}
	if (i > 1 && cub3d->events.start == 2)
		raycasting(cub3d, 0);
}

int	action(t_cub3d *cub3d)
{
	int	i;

	i = 1;
	if (cub3d->events.down_move && !cub3d->events.up_move && i++)
		down3d(cub3d, 0, 0);
	if (cub3d->events.up_move && !cub3d->events.down_move && i++)
		up3d(cub3d, 0, 0);
	if (cub3d->events.left_move && !cub3d->events.right_move && i++)
		left3d(cub3d, 0, 0);
	if (cub3d->events.right_move && !cub3d->events.left_move && i++)
		right3d(cub3d, 0, 0);
	if (cub3d->events.right_row && !cub3d->events.left_row && i++)
		cub3d->map->player.angle += RET_ANGLE;
	if (cub3d->events.left_row && !cub3d->events.right_row && i++)
		cub3d->map->player.angle -= RET_ANGLE;
	if (cub3d->events.map && i++)
		cub3d->events.map = 0;
	if (cub3d->events.esc)
		close_window3d(cub3d);
	if (cub3d->events.old_img != cub3d->gun.img && i++)
		cub3d->events.old_img = cub3d->gun.img;
	help_action(cub3d, i);
	return (0);
}

int	mousemove(int x, int y, t_cub3d *cub3d)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (cub3d->last_m_p == -1)
			cub3d->last_m_p = x;
		if (cub3d->last_m_p - x < 0 && cub3d->events.start)
		{
			cub3d->map->player.angle += RET_ANGLE + RET_ANGLE;
			raycasting(cub3d, 0);
			cub3d->last_m_p = x;
		}
		else if (cub3d->last_m_p - x > 0 && cub3d->events.start)
		{
			cub3d->map->player.angle -= RET_ANGLE + RET_ANGLE;
			raycasting(cub3d, 0);
			cub3d->last_m_p = x;
		}
	}
	return (0);
}

void	help_mouseclick(int butt, int x, int y, t_cub3d *cub3d)
{
	(void)x;
	(void)y;
	if (butt == 1 && cub3d->events.shoot == 1)
		shoot(cub3d);
	if (butt == 2)
	{
		system("afplay sounds/gun2.mp3&");
		cub3d->events.shoot2 = 1;
		if (cub3d->events.shoot)
			cub3d->events.shoot = 0;
		else
			cub3d->events.shoot = 1;
	}
}

int	mouseclick(int butt, int x, int y, t_cub3d *cub3d)
{
	if (x >= 460 && x <= 811 && y >= 445 && y <= 592 && !cub3d->events.start)
	{
		system("afplay sounds/click.mp3&");
		cub3d->events.start = 1;
	}
	if (butt == 3)
	{
		system("afplay sounds/popup.mp3&");
		if (!cub3d->mmap)
			cub3d->mmap = 1;
		else
			cub3d->mmap = 0;
		cub3d->events.map = 1;
	}
	help_mouseclick(butt, x, y, cub3d);
	return (0);
}
