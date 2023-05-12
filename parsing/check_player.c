/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:31:24 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/04/03 02:02:19 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycasting.h"

void	get_player(t_cub3d *cub3d, int x, int y, int *found)
{
	int	n;

	cub3d->map->player.x = y * SIZE + SIZE / 2;
	cub3d->map->player.y = x * SIZE + SIZE / 2;
	if (cub3d->map->map[x][y] == 'N')
		n = 90;
	else if (cub3d->map->map[x][y] == 'S')
		n = 270;
	else if (cub3d->map->map[x][y] == 'E')
		n = 0;
	else
		n = 180;
	cub3d->map->player.angle = n;
	(*found)++;
}

void	check_player_helper(int found, int bad_character)
{
	if (found != 1)
		ft_error("one player must exist in the map !", NULL);
	if (bad_character)
		ft_error("bad charachter in the map !", NULL);
}

void	check_player(t_cub3d *cub3d)
{
	int	i;
	int	j;
	int	found;
	int	bad_character;

	found = 0;
	bad_character = 0;
	i = -1;
	j = 0;
	cub3d->map->empty_nbr = 0;
	while (cub3d->map->map[++i])
	{
		while (cub3d->map->map[i][j])
		{
			if (in_set(cub3d->map->map[i][j], "ENSW"))
				get_player(cub3d, i, j, &found);
			else if (!in_set(cub3d->map->map[i][j], "1 0D\n"))
				bad_character++;
			if (cub3d->map->map[i][j++] == ' ')
				cub3d->map->empty_nbr++;
		}
		j = 0;
	}
	check_player_helper(found, bad_character);
}
