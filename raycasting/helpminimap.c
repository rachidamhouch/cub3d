/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpminimap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 07:18:29 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/02 07:19:14 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	make_it_circular(t_cub3d *cub3d)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = MINI_MAP_HEIGHT / 2;
	y = MINI_MAP_HEIGHT / 2;
	i = 0;
	while (i < MINI_MAP_WIDTH)
	{
		j = 0;
		while (j < MINI_MAP_HEIGHT)
		{
			if (sqrt(pow(x - i, 2) + pow(y - j, 2)) > (MINI_MAP_HEIGHT / 2))
				my_mlx_pixel_put2(&cub3d->img, i, j, 0xFFFFFFFF);
			j++;
		}
		i++;
	}
}

void	help_render_mini_map(t_cub3d *cub3d, int *t, int j)
{
	j = cub3d->map->player.x * (((float)MINI_MAP_SIZE / (float)SIZE));
	t[0] = cub3d->map->player.y * (((float)MINI_MAP_SIZE / (float)SIZE));
	player(cub3d, j - t[2], t[0] - t[3], 5);
	make_it_circular(cub3d);
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, cub3d->imgs.minimap, \
		WIDTH - MINI_MAP_WIDTH - 57, HEIGHT - MINI_MAP_HEIGHT - 59);
	mlx_put_image_to_window(cub3d->mlx3d, cub3d->win3d, cub3d->img.img, \
		WIDTH - MINI_MAP_WIDTH - 30, HEIGHT - MINI_MAP_HEIGHT - 30);
}
