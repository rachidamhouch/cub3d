/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:06:15 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:00:10 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;
	int	c;
	int	xy[2];

	i = 0;
	while (i < SIZE && color)
	{
		j = 0;
		if (i == SIZE - 1)
			color = get_color("0,130,0");
		while (j < SIZE)
		{
			c = color;
			if (j == 0)
				c = get_color("0,130,0");
			xy[0] = x + i;
			xy[1] = y + j;
			my_mlx_pixel_put4(cub3d, &cub3d->img, xy, c);
			j++;
		}
		i++;
	}
}

static int	help_draw_line(t_cub3d *cub3d)
{
	if (cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
			[(int)cub3d->draw.x / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)cub3d->draw.y + 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
		return (1);
	if (cub3d->map->square_map[((int)cub3d->draw.y - 1) / SIZE] \
		[(int)cub3d->draw.x / SIZE] == '1'
		&& cub3d->map->square_map[(int)cub3d->draw.y / SIZE] \
		[((int)cub3d->draw.x + 1) / SIZE] == '1')
		return (1);
	return (0);
}

static void	draw_line(t_cub3d *cub3d, float angle)
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
	while (1)
	{
		my_mlx_pixel_put(&cub3d->img, cub3d->draw.x, cub3d->draw.y, 0xFF0000);
		cub3d->draw.x -= cub3d->draw.increment_x;
		cub3d->draw.y -= cub3d->draw.increment_y;
		if (help_draw_line(cub3d))
			break ;
	}
}

static void	render_player(t_cub3d *cub3d)
{
	float	angel_size;
	float	start;
	int		i;

	angel_size = 60.0 / WIDTH;
	start = cub3d->map->player.angle - 30;
	i = 0;
	while (i <= WIDTH)
	{
		draw_line(cub3d, start);
		start += angel_size;
		i++;
	}
}

void	render_map(t_cub3d *cub3d, int x, int y, int i)
{
	int		j;
	int		color;
	char	**str;

	str = cub3d->map->square_map;
	mlx_clear_window(cub3d->mlx, cub3d->win);
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			if (str[i][j] == '1' || str[i][j] == ' ' || str[i][j] == 'K')
				color = 0;
			else
				color = get_color("210, 180, 222");
			put_pixel(cub3d, x, y, color);
			j++;
			x += SIZE;
		}
		i++;
		y += SIZE;
	}
	render_player(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img, 0, 0);
}
