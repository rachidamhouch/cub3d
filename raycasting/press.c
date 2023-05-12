/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:26:22 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/03/30 03:47:05 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

int	close_window2d(t_cub3d *cub3d)
{
	printf("%sWindow Closed\n%s", RED, RESET);
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	ft_free(cub3d);
	return (0);
}

int	close_window3d(t_cub3d *cub3d)
{
	printf("%sWindow Closed\n%s", RED, RESET);
	mlx_destroy_window(cub3d->mlx3d, cub3d->win3d);
	ft_free(cub3d);
	return (0);
}
