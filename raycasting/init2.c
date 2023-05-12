/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:34:30 by ramhouch          #+#    #+#             */
/*   Updated: 2023/05/12 17:44:37 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	help_int4(t_cub3d *cub3d)
{
	if (!cub3d->imgs.no.img)
		peint_error();
	cub3d->imgs.no.addr = mlx_get_data_addr(cub3d->imgs.no.img, \
		&cub3d->imgs.no.bits_per_pixel, &cub3d->imgs.no.line_length, \
		&cub3d->imgs.no.endian);
	cub3d->imgs.so.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		cub3d->map->so_texture, &cub3d->imgs.so.width, &cub3d->imgs.so.hight);
	if (!cub3d->imgs.so.img)
		peint_error();
	cub3d->imgs.so.addr = mlx_get_data_addr(cub3d->imgs.so.img, \
		&cub3d->imgs.so.bits_per_pixel, &cub3d->imgs.so.line_length, \
		&cub3d->imgs.so.endian);
	cub3d->imgs.we.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		cub3d->map->we_texture, &cub3d->imgs.we.width, &cub3d->imgs.we.hight);
	if (!cub3d->imgs.we.img)
		peint_error();
}

void	help_int5(t_cub3d *cub3d)
{
	int	a;
	int	b;

	cub3d->gun.g2 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/2.xpm", &a, &b);
	cub3d->gun.g3 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/3.xpm", &a, &b);
	cub3d->gun.g4 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/4.xpm", &a, &b);
	cub3d->gun.g5 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/5.xpm", &a, &b);
	cub3d->gun.img = cub3d->gun.g0;
	cub3d->events.old_img = cub3d->gun.img;
	cub3d->imgs.door.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/door.xpm", &cub3d->imgs.door.width, \
		&cub3d->imgs.door.hight);
	cub3d->imgs.start = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/cub3d.xpm", &a, &b);
	cub3d->imgs.door.addr = mlx_get_data_addr(cub3d->imgs.door.img, \
		&cub3d->imgs.door.bits_per_pixel, &cub3d->imgs.door.line_length, \
		&cub3d->imgs.door.endian);
	cub3d->events.closed = 0;
	cub3d->events.start = 0;
}
