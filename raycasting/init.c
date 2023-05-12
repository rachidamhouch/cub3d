/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:14:06 by ramhouch          #+#    #+#             */
/*   Updated: 2023/05/12 17:43:56 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	peint_error(void)
{
	printf("Bad textures\n");
	exit(1);
}

static void	help_int1(t_cub3d *cub3d)
{
	cub3d->mlx3d = mlx_init();
	cub3d->img3d.img = mlx_new_image(cub3d->mlx3d, WIDTH, HEIGHT + 1);
	cub3d->img3d.addr = mlx_get_data_addr(cub3d->img3d.img, \
		&cub3d->img3d.bits_per_pixel, &cub3d->img3d.line_length, \
		&cub3d->img3d.endian);
	cub3d->img.img = mlx_new_image(cub3d->mlx3d, \
		MINI_MAP_WIDTH, MINI_MAP_HEIGHT);
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
		&cub3d->img.bits_per_pixel, \
		&cub3d->img.line_length, &cub3d->img.endian);
	cub3d->win3d = mlx_new_window(cub3d->mlx3d, WIDTH, HEIGHT, "Cub3d");
	cub3d->colors.e = get_color("46, 204, 113");
	cub3d->colors.n = get_color("52, 152, 219");
	cub3d->colors.s = get_color("192, 57, 43");
	cub3d->colors.w = get_color("244, 208, 63");
	cub3d->events.down_move = 0;
	cub3d->events.esc = 0;
	cub3d->events.left_move = 0;
	cub3d->events.left_row = 0;
	cub3d->events.right_move = 0;
	cub3d->events.right_row = 0;
	cub3d->events.up_move = 0;
	cub3d->events.map = 0;
	cub3d->mmap = 0;
	cub3d->draw.old_color = 0;
}

static void	help_int2(t_cub3d *cub3d)
{
	int	a;
	int	b;

	cub3d->events.shoot = 0;
	cub3d->events.shoot2 = 0;
	cub3d->last_m_p = -1;
	cub3d->imgs.minimap = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/minimap.xpm", &a, &b);
	cub3d->imgs.ea.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		cub3d->map->ea_texture, &cub3d->imgs.ea.width, &cub3d->imgs.ea.hight);
	if (!cub3d->imgs.ea.img)
		peint_error();
	cub3d->imgs.ea.addr = mlx_get_data_addr(cub3d->imgs.ea.img, \
		&cub3d->imgs.ea.bits_per_pixel, &cub3d->imgs.ea.line_length, \
		&cub3d->imgs.ea.endian);
	cub3d->imgs.no.img = mlx_xpm_file_to_image(cub3d->mlx3d, \
		cub3d->map->no_texture, &cub3d->imgs.no.width, &cub3d->imgs.no.hight);
	help_int4(cub3d);
}

static void	help_int3(t_cub3d *cub3d)
{
	help_int1(cub3d);
	help_int2(cub3d);
	cub3d->imgs.we.addr = mlx_get_data_addr(cub3d->imgs.we.img, \
		&cub3d->imgs.we.bits_per_pixel, &cub3d->imgs.we.line_length, \
		&cub3d->imgs.we.endian);
	cub3d->bigmap.s = (float)WIDTH / \
		(ft_strlen(cub3d->map->square_map[0]) * SIZE);
	if (cub3d->bigmap.s > (float)HEIGHT / \
		(len_double(cub3d->map->square_map) * SIZE))
		cub3d->bigmap.s = (float)HEIGHT / \
			(len_double(cub3d->map->square_map) * SIZE);
	cub3d->bigmap.size = (float)SIZE * cub3d->bigmap.s;
	cub3d->bigmap.with = (ft_strlen(cub3d->map->square_map[0]) - 1) \
		* cub3d->bigmap.size - 10;
	cub3d->bigmap.hight = len_double(cub3d->map->square_map) \
		* cub3d->bigmap.size;
	cub3d->bigmap.img.img = mlx_new_image(cub3d->mlx3d, \
		cub3d->bigmap.with, cub3d->bigmap.hight);
	cub3d->bigmap.img.addr = mlx_get_data_addr(cub3d->bigmap.img.img, \
		&cub3d->bigmap.img.bits_per_pixel, \
		&cub3d->bigmap.img.line_length, &cub3d->bigmap.img.endian);
}

void	init(t_cub3d *cub3d)
{
	int	a;
	int	b;

	if (ON2D)
	{
		cub3d->mlx = mlx_init();
		cub3d->width = (ft_strlen(cub3d->map->square_map[0])) * SIZE;
		cub3d->hight = len_double(cub3d->map->square_map) * SIZE;
		cub3d->win = mlx_new_window(cub3d->mlx, cub3d->width - \
			SIZE, cub3d->hight, "Cub3d");
		cub3d->img.img = mlx_new_image(cub3d->mlx, cub3d->width, cub3d->hight);
		cub3d->img.addr = mlx_get_data_addr(cub3d->img.img, \
			&cub3d->img.bits_per_pixel, \
			&cub3d->img.line_length, &cub3d->img.endian);
	}
	if (ON3D)
	{
		help_int3(cub3d);
		cub3d->gun.g0 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/0.xpm", &a, &b);
		cub3d->gun.g1 = mlx_xpm_file_to_image(cub3d->mlx3d, \
		"textures/gun/1.xpm", &a, &b);
		help_int5(cub3d);
	}
}
