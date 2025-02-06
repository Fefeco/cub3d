/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:21:49 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 19:23:53 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <sys/time.h>
# include <stdbool.h>
# include "mlx.h"
# include "keys.h"
# include "error.h"

# define HEIGHT		768
# define WIDTH		1024
# define TILE		64
# define STEP_SZ	5
# define SPEED_ROT	3
# define FOV		62
# define EPSILON	1e-10

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_keys
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_mlx
{
	void	*disp;
	void	*win;
}				t_mlx;

typedef struct s_int_vector
{
	int	x;
	int	y;
}				t_ivec;

typedef struct s_double_vector
{
	double	x;
	double	y;
}				t_dvec;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_x_pxl;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_textures
{
	char	*file;
	t_img	data;
	int		w;
	int		h;
}				t_tex;

typedef struct s_wall
{
	double			line_height;
	unsigned int	px_color;
	double			start;
	double			end;
}				t_wall;

typedef struct s_player
{
	t_dvec	pos;
	double	ang;
}				t_player;

typedef struct s_ray
{
	double	ang;
	double	dst;
	char	axis;
	t_dvec	delta;
	t_ivec	step;
	t_dvec	delta_dst;
	t_dvec	start;
	t_dvec	hit;
}				t_ray;

typedef struct s_game
{
	t_mlx		mlx;
	t_color		ceiling;
	t_keys		keys;
	t_color		floor;
	t_tex		no;
	t_tex		so;
	t_tex		ea;
	t_tex		we;
	t_img		render;
	t_img		draw;
	bool		ready_for_map;
	bool		key_press;
	t_player	ply;
	char		**map;
}				t_game;

// print_err.c
int		print_err(const char *str, int ret);

// map_validations.c
int		ft_check_extension(const char *filename, const char *ext);

// exit.c
int		clean_exit(t_game *cub3d, const char *error, int error_nb);
void	clean_game_ptrs(t_game *cub3d);

// set_params.c
void	set_game_params(char *filename, t_game *cub3d);

// extract.c
int		extract_params(char **line_ref, t_game *cub3d);

// extract_coord.c
int		extract_coord(const char *line, t_game *cub3d);

// extract_color.c
int		extract_color(const char *line, t_game *cub3d);
bool	color_ok(t_color *color);

// free.c
void	free_map(char **map);
void	free_image(t_img *data, void *disp);
void	free_texture(t_tex *tex, void *disp);
void	free_mlx(t_mlx *mlx);

// draw_tools.c
int		create_trgb(int t, int r, int g, int b);
void	put_pxl_on_img(t_img *data, int x, int y, int color);

// map_tools.c
int		is_ready_for_map(t_game *game);
void	validate_map(t_game *cub3d);

// moves.c
int		handle_key_press(int key, t_game *cub3d);
int		handle_key_release(int key, t_game *cub3d);
void	try_move(int key, t_game *cub3d);
void	rotate(int key, t_player *ply);

// set_player.c
void	set_player(t_game *cub3d);

// add_line_to_map.c
int		add_line_to_map(const char *line, t_game *cub3d);

// test.c
void	test(const t_game *cub3d);

// init.c
void	init_game(t_game *cub3d);

// init_structs.c
void	init_t_game(t_game *cub3d);
void	init_image(t_img *data);

// switch_img.c
void	switch_img(t_img *img1, t_img *img2);

// create_image.c
void	create_image(t_game *cub3d);

// render.c
int		render(t_game *cub3d);

// utils.c
int		check_wall(int x, int y, char **map);
double	norm_ang(double ang);
double	deg_to_rad(int deg);
int		rad_to_deg(double rad);
bool	file_access(char *value);

// dda.c
void	dda(t_ray *ray, char **map);
void	set_deltas(t_dvec *delta, double ang);

// dda_utils.c
t_ivec	get_map_coords(t_dvec ply_pos);
void	set_delta_distances(t_dvec *delta_dst, t_dvec delta);
void	set_step_directions(t_ray *ray);

// render_walls.c
void	render_walls(t_game *cub3d);

// draw_walls.c
void	draw_wall(t_game *cub3d, int x, t_wall wall, t_ray ray);

// set_desltas.c
void	set_deltas(t_dvec *delta, double ang);

// init_textures.c
void	init_textures(t_game *cub3d);

#endif
