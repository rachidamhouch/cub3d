/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 08:01:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:36:25 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	int	i;
	int	j;
	int	xy[2];
	int	limits[2];

	i = 0;
	limits[0] = cub3d->bigmap.with;
	limits[1] = cub3d->bigmap.hight;
	while (i < cub3d->bigmap.size && color)
	{
		j = 0;
		while (j < cub3d->bigmap.size)
		{
			xy[0] = x + i;
			xy[1] = y + j;
			my_mlx_pixel_put3(&cub3d->bigmap.img, xy, color, limits);
			j++;
		}
		i++;
	}
}

static void	playerr(t_cub3d *cub3d, int x, int y, int radius)
{
	int	i;
	int	j;
	int	xy[2];
	int	limits[2];

	limits[0] = cub3d->bigmap.with;
	limits[1] = cub3d->bigmap.hight;
	i = x - radius;
	while (i < x + radius)
	{
		j = y - radius;
		while (j < y + radius)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
			{
				xy[0] = i;
				xy[1] = j;
				my_mlx_pixel_put3(&cub3d->bigmap.img, xy, 0xFF0000, limits);
			}
			j++;
		}
		i++;
	}
}

static void	help_render_mbigmap(t_cub3d *cub3d)
{
	int	xp;
	int	yp;

	xp = cub3d->map->player.x * (((float)cub3d->bigmap.size / (float)SIZE));
	yp = cub3d->map->player.y * (((float)cub3d->bigmap.size / (float)SIZE));
	playerr(cub3d, xp, yp, 5);
	xp = (WIDTH - cub3d->bigmap.with) / 2;
	yp = (HEIGHT - cub3d->bigmap.hight) / 2;
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, \
		cub3d->bigmap.img.img, xp, yp);
}

int	help_render_mbigmap2(char n)
{
	int	color;

	if (n == '1' || n == ' ' || n == 'K')
		color = 0x9F666666;
	else if (n == 'D')
		color = 0x00FF00;
	else
		color = 100 << 24 | get_color("229, 152, 102");
	return (color);
}

void	render_mbigmap(t_cub3d *cub3d, int x, int y, int i)
{
	int		j;
	int		color;
	char	**str;

	str = cub3d->map->square_map;
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			color = help_render_mbigmap2(str[i][j]);
			put_pixel(cub3d, x, y, color);
			j++;
			x += cub3d->bigmap.size;
		}
		i++;
		y += cub3d->bigmap.size;
	}
	help_render_mbigmap(cub3d);
}
