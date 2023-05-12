/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:15:36 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 01:59:27 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put2(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > MINI_MAP_WIDTH || x < 0 || y > MINI_MAP_HEIGHT || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put3(t_data *data, int *xy, int color, int	*limits)
{
	char	*dst;

	if (xy[0] > limits[0] || xy[0] < 0 || xy[1] > limits[1] || xy[1] < 0)
		return ;
	dst = data->addr + (xy[1] * data->line_length + \
		xy[0] * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put4(t_cub3d *cub3d, t_data *data, int *xy, int color)
{
	char	*dst;

	if (xy[0] > cub3d->width || xy[0] < 0 || xy[1] > cub3d->hight || xy[1] < 0)
		return ;
	dst = data->addr + (xy[1] * data->line_length + xy[0] \
		* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
