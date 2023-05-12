/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 03:09:37 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:58:53 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_pexel(t_cub3d *cub3d, int i, int my, float size)
{
	int	x;
	int	y;

	if (cub3d->draw.d == 1)
	{
		x = (int)cub3d->draw.y % SIZE;
		y = (i + my) / size;
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.x - cub3d->draw.x > 0)
			return (get_pexel_from_img(&cub3d->imgs.ea, x, y));
		return (get_pexel_from_img(&cub3d->imgs.no, x, y));
	}
	if (cub3d->draw.d == 3)
	{
		x = (int)cub3d->draw.x % SIZE;
		y = (i + my) / size;
		if (cub3d->draw.type == 'D')
			return (get_pexel_from_img(&cub3d->imgs.door, x, y));
		if (cub3d->map->player.y - cub3d->draw.y > 0)
			return (get_pexel_from_img(&cub3d->imgs.so, x, y));
		return (get_pexel_from_img(&cub3d->imgs.we, x, y));
	}
	return (0);
}

int	help(char n)
{
	int	color;

	if (n == '1' || n == ' ' || n == 'K')
		color = get_color("100,100,100");
	else if (n == 'D')
		color = 0x00FF00;
	else
		color = get_color("229, 152, 102");
	return (color);
}
