/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:28:03 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:56:43 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

static	int	check(t_cub3d *cub3d, int x, int y)
{
	int	xp;
	int	yp;

	xp = cub3d->map->player.x * (((float)MINI_MAP_SIZE / (float)SIZE));
	yp = cub3d->map->player.y * (((float)MINI_MAP_SIZE / (float)SIZE));
	if (abs(x - xp) < (MINI_MAP_WIDTH / 2) && \
		abs(y - yp) < (MINI_MAP_HEIGHT / 2))
		return (1);
	return (0);
}

static void	put_pixel(t_cub3d *cub3d, int x, int y, int *t)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < MINI_MAP_SIZE && t[0])
	{
		j = 0;
		while (j < MINI_MAP_SIZE)
		{
			if (check(cub3d, x + i, y + j))
			{
				if (t[1])
				{
					t[1] = 0;
					t[2] = x + i;
					t[3] = y + j;
					my_mlx_pixel_put2(&cub3d->img, 0, 0, t[0]);
				}
				else
					my_mlx_pixel_put2(&cub3d->img, x + i - t[2], \
						y + j - t[3], t[0]);
			}
			j++;
		}
	}
}

void	clear_img(t_cub3d *cub3d)
{
	int	i;
	int	y;

	i = 0;
	while (i < MINI_MAP_WIDTH)
	{
		y = 0;
		while (y < MINI_MAP_HEIGHT)
		{
			my_mlx_pixel_put2(&cub3d->img, i, y, get_color("229, 152, 102"));
			y++;
		}
		i++;
	}
}

void	player(t_cub3d *cub3d, int x, int y, int radius)
{
	int	i;
	int	j;

	i = x - radius;
	while (i < x + radius)
	{
		j = y - radius;
		while (j < y + radius)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
				my_mlx_pixel_put2(&cub3d->img, i, j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	render_mini_map(t_cub3d *cub3d, int x, int y, int i)
{
	int		j;
	char	**str;
	int		t[4];

	str = cub3d->map->square_map;
	t[1] = 1;
	clear_img(cub3d);
	while (str[i])
	{
		j = 0;
		x = 0;
		while (str[i][j])
		{
			t[0] = help(str[i][j]);
			put_pixel(cub3d, x, y, t);
			j++;
			x += MINI_MAP_SIZE;
		}
		i++;
		y += MINI_MAP_SIZE;
	}
	help_render_mini_map(cub3d, t, j);
}
