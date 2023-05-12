/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:17:05 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:49:53 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static int	help_draw_line3(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		cub3d->draw.type = '1';
		return (1);
	}
	if (cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		cub3d->draw.type = '1';
		return (1);
	}
	if (cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == 'D'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == 'D')
	{
		cub3d->draw.type = 'D';
		return (1);
	}
	return (0);
}

static int	help_draw_line1(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
			[(int)cub3d->draw.x / SIZE] == '1')
	{
		cub3d->draw.type = '1';
		return (1);
	}
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
	{
		cub3d->draw.type = '1';
		return (1);
	}
	if (help_draw_line3(cub3d))
		return (1);
	return (help_draw_lined(cub3d));
}

static void	draw_line(t_cub3d *cub3d, float angle)
{
	help_draw_line2(cub3d, angle);
	while (1)
	{
		if (is_wall(cub3d, cub3d->draw.x - \
			cub3d->draw.increment_x, cub3d->draw.y))
			cub3d->draw.d = 1;
		if (is_wall(cub3d, cub3d->draw.x, cub3d->draw.y - \
			cub3d->draw.increment_y))
			cub3d->draw.d = 3;
		cub3d->draw.x -= cub3d->draw.increment_x;
		cub3d->draw.y -= cub3d->draw.increment_y;
		if (help_draw_line1(cub3d))
			break ;
	}
	cub3d->draw.distance = sqrt(pow(cub3d->draw.x - cub3d->map->player.x, 2) \
		+ pow(cub3d->draw.y - cub3d->map->player.y, 2)) * \
		cos((angle - cub3d->map->player.angle) * PI / 180);
}

void	draw_wall(t_cub3d *cub3d, int i, int y)
{
	int		m;
	int		n;
	int		my;
	float	size;

	size = help_draw_wall(cub3d, &m, &n, &my);
	while (y < (HEIGHT - cub3d->draw.wall_height) / 2)
	{
		my_mlx_pixel_put(&cub3d->img3d, i, y, plus_transp(cub3d, \
			rgb_to_int(*(cub3d->map->ciel_color)), m++, 0));
		y++;
	}
	while (y < HEIGHT - ((HEIGHT - cub3d->draw.wall_height) / 2))
	{
		my_mlx_pixel_put(&cub3d->img3d, i, y, get_pexel(cub3d, n, my, size));
		y++;
		n++;
	}
	while (y < HEIGHT)
	{
		my_mlx_pixel_put(&cub3d->img3d, i, y, \
			plus_transp(cub3d, rgb_to_int(*(cub3d->map->floor_color)), m--, 0));
		y++;
	}
}

void	raycasting(t_cub3d *cub3d, int i)
{
	float	angel_size;
	float	start;

	mlx_clear_window(cub3d->mlx3d, cub3d->win3d);
	angel_size = 60.0 / WIDTH;
	start = cub3d->map->player.angle - 30;
	while (i <= WIDTH)
	{
		draw_line(cub3d, start);
		help_raycasting(cub3d, &i, &start);
		draw_wall(cub3d, i, 0);
		start += angel_size;
		i++;
	}
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, cub3d->img3d.img, 0, 0);
	if (cub3d->events.shoot)
		mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, \
			cub3d->gun.img, WIDTH / 2 - 190, HEIGHT / 2 - 40);
	if (!cub3d->mmap)
		render_mini_map(cub3d, 0, 0, 0);
	else
		render_mbigmap(cub3d, 0, 0, 0);
}
