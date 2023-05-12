/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:34:46 by ramhouch          #+#    #+#             */
/*   Updated: 2023/04/04 02:50:47 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# include "../includes/parsing.h"

# define HEIGHT 720
# define WIDTH 1280
# define MINI_MAP_HEIGHT 200
# define MINI_MAP_WIDTH 200
# define PI 3.14159265
# define TWO_PI 6.2831853
# define VEW_ANGLE 60
# define NUM_RAYS WIDTH
# define SPEED 50
# define RET_ANGLE 5
# define SIZE 64
# define MINI_MAP_SIZE 15
# define ON2D 0
# define ON3D 1

void	init(t_cub3d *cub3d);
int		close_window3d(t_cub3d *cub3d);
int		close_window2d(t_cub3d *cub3d);
int		get_color(char *text);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	render_map(t_cub3d *cub3d, int x, int y, int i);
void	up(t_cub3d *cub3d, int x, int y);
void	down(t_cub3d *cub3d, int x, int y);
void	left(t_cub3d *cub3d, int x, int y);
void	right(t_cub3d *cub3d, int x, int y);
int		inter(t_cub3d *cub3d);
void	raycasting(t_cub3d *cub3d, int i);
int		check_movements(t_cub3d *cub3d, int x, int y);
void	up3d(t_cub3d *cub3d, int x, int y);
void	down3d(t_cub3d *cub3d, int x, int y);
void	left3d(t_cub3d *cub3d, int x, int y);
void	right3d(t_cub3d *cub3d, int x, int y);
int		key_hook(int keycode, t_cub3d *cub3d);
int		press(int keycode, t_cub3d *cub3d);
int		depress(int keycode, t_cub3d *cub3d);
int		action(t_cub3d *cub3d);
int		plus_transp(t_cub3d *cub3d, int color, int y, int i);
int		shader(int color, float percent);
int		check_movements2(t_cub3d *cub3d, int x, int y);
int		mousemove(int x, int y, t_cub3d *cub3d);
void	my_mlx_pixel_put2(t_data *data, int x, int y, int color);
void	render_mini_map(t_cub3d *cub3d, int x, int y, int i);
void	my_mlx_pixel_put3(t_data *data, int *xy, int color, int	*limits);
void	render_mbigmap(t_cub3d *cub3d, int x, int y, int i);
int		get_pexel_from_img(t_data *data, int x, int y);
int		get_pexel(t_cub3d *cub3d, int i, int my, float size);
void	player(t_cub3d *cub3d, int x, int y, int radius);
void	make_it_circular(t_cub3d *cub3d);
void	help_render_mini_map(t_cub3d *cub3d, int *t, int j);
int		is_wall(t_cub3d *cub3d, int x, int y);
void	help_draw_line2(t_cub3d *cub3d, float angle);
int		mouseclick(int butt, int x, int y, t_cub3d *cub3d);
void	my_mlx_pixel_put4(t_cub3d *cub3d, t_data *data, int *xy, int color);
void	help_int4(t_cub3d *cub3d);
void	help_int5(t_cub3d *cub3d);
void	peint_error(void);
void	help_action(t_cub3d *cub3d, int i);
void	help_mouseclick(int butt, int x, int y, t_cub3d *cub3d);
void	shoot(t_cub3d *cub3d);
int		help(char n);
void	*closedoor(void *ptr);
void	help_raycasting(t_cub3d *cub3d, int *i, float *start);
float	help_draw_wall(t_cub3d *cub3d, int *m, int *n, int *my);
int		help_draw_lined(t_cub3d *cub3d);
#endif
