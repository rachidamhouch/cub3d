/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 03:37:48 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 00:26:55 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	get_color(char *text)
{
	int		c;
	char	**rgb;
	int		color;
	int		i;

	color = 0;
	i = 0;
	rgb = ft_split(text, ',');
	c = ft_atoi(rgb[0]) << 16;
	color += c;
	c = ft_atoi(rgb[1]) << 8;
	color += c;
	c = ft_atoi(rgb[2]);
	color += c;
	while (rgb[i])
		free(rgb[i++]);
	free(rgb);
	return (color);
}

int	plus_transp(t_cub3d *cub3d, int color, int y, int i)
{
	int	plus;
	int	percent;

	if (i)
	{
		plus = 255;
		percent = cub3d->draw.wall_height * 100 / HEIGHT;
		if (percent > 100)
			percent = 100;
		if (percent < 10)
			percent = 10;
		plus -= plus * percent / 100;
		plus = plus << 24;
		return (plus + cub3d->draw.color);
	}
	plus = (float)y / 2;
	plus = plus << 24;
	return (plus + color);
}

int	get_pexel_from_img(t_data *data, int x, int y)
{
	char	*dst;

	if (x > data->width || x < 0 || y > data->hight || y < 0)
		return (-1);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
