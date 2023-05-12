/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hidhmmou <hidhmmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:01 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/13 11:21:05 by hidhmmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	free_double(char	**arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_free(t_cub3d *cub3d)
{
	int	i;

	i = -1;
	if (cub3d->map->content)
		free_double(cub3d->map->content);
	if (cub3d->map->map)
		free_double(cub3d->map->map);
	exit(0);
}

void	ft_error(char *message, t_cub3d *cub3d)
{
	printf("%sError\n%s%s\n", RED, message, RESET);
	if (cub3d)
		ft_free(cub3d);
	exit(EXIT_FAILURE);
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
