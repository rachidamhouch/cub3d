/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramhouch <ramhouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:11:07 by hidhmmou          #+#    #+#             */
/*   Updated: 2023/04/04 02:01:53 by ramhouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "../libft/libft.h"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define RESET "\033[0m"
/*--keys--*/
# define RIGHT_MOVE 2
# define LEFT_MOVE 0
# define DOWN_MOVE 1
# define UP_MOVE 13
# define RIGHT_ROW 124
# define LEFT_ROW 123
# define ESC 53
# define CLOSE 17
# define MAP 46

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_events
{
	int		right_move;
	int		left_move;
	int		down_move;
	int		up_move;
	int		right_row;
	int		left_row;
	int		esc;
	int		map;
	int		shoot;
	int		shoot2;
	void	*old_img;
	int		closed;
	int		start;
}	t_events;

typedef struct s_player
{
	int		x;
	int		y;
	int		angle;
}	t_player;
typedef struct s_map
{
	int			rows;
	int			cols;
	t_player	player;
	char		**content;
	char		**check_map;
	char		**square_map;
	char		**map;
	char		*so_texture;
	char		*no_texture;
	char		*ea_texture;
	char		*we_texture;
	char		*f_color;
	char		*c_color;
	t_color		*floor_color;
	int			ff_color;
	int			cc_color;
	t_color		*ciel_color;
	int			empty_nbr;
	size_t		max_len;
}		t_map;

typedef struct s_colors
{
	int	n;
	int	s;
	int	e;
	int	w;
}	t_colors;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		hight;
	int		width;
}				t_data;

typedef struct s_imgs
{
	void	*minimap;
	void	*start;
	t_data	we;
	t_data	so;
	t_data	no;
	t_data	ea;
	t_data	door;
}	t_imgs;

typedef struct s_gun
{
	void	*g0;
	void	*g1;
	void	*g2;
	void	*g3;
	void	*g4;
	void	*g5;
	void	*img;
}	t_gun;
typedef struct s_bigmap
{
	float		s;
	int			with;
	int			hight;
	int			size;
	t_data		img;
}	t_bigmap;

typedef struct s_draw
{
	int			dx;
	int			dy;
	float		increment_x;
	float		increment_y;
	float		x;
	float		y;
	float		distance;
	float		wall_height;
	int			color;
	int			old_color;
	int			d;
	int			type;
}	t_draw;

typedef struct s_cub3d
{
	t_map		*map;
	void		*mlx;
	void		*win;
	void		*mlx3d;
	void		*win3d;
	t_data		img;
	t_data		img3d;
	t_draw		draw;
	t_colors	colors;
	t_events	events;
	int			last_m_p;
	t_imgs		imgs;
	t_bigmap	bigmap;
	int			mmap;
	t_gun		gun;
	pthread_t	th;
	int			hight;
	int			width;
}	t_cub3d;

void	ft_error(char *message, t_cub3d *cub3d);
void	free_double(char **content);
void	ft_free(t_cub3d *cub3d);
char	*get_next_line(int fd);
void	pre_check_map(char *file);
void	fill_content(char *map_file, t_cub3d *cub3d);
void	check_content(t_cub3d *cub3d);
char	*get_from_file(char **content, char *target);
int		find(char **content, char *target, int flag);
void	get_colors(t_cub3d *cub3d);
void	get_textures(t_cub3d *cub3d);
void	check_textures(char	**content);
void	check_colors(char	**content);
int		get_rgb(int color);
void	get_colors(t_cub3d *cub3d);
int		check_colors_format(char **tab);
void	check_player(t_cub3d *cub3d);
int		in_set(char c, char *set);
int		check_surrounded(t_cub3d *cub3d);
int		check_outsider_floor(t_cub3d *cub3d);
int		rgb_to_int(t_color color);
int		check_floor_outside_1(char **map);
int		check_floor_outside_2(char **map);
int		fast_check(char	*line, int i, int len);
int		in_set(char c, char *set);
int		map_len(char **content);
int		len_double(char **map);
void	ft_func_helper(t_cub3d *cub3d, int x, int y);
void	virus_floor(t_cub3d *cub3d, int x, int y);
void	get_check_map(t_cub3d *cub3d);
void	get_square_map(t_cub3d *cub3d);
void	get_map(t_cub3d *cub3d);
#endif