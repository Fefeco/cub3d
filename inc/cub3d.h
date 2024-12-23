/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:21:49 by davifer2          #+#    #+#             */
/*   Updated: 2024/12/23 14:36:57 by fcarranz         ###   ########.fr       */
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

# define HEIGHT		600
# define WIDTH		800
# define TILE		16
# define STEP_SZ	4

# define MAP_WALL_COLOR 0x00433535
# define GRID_COLOR		0x00C0C0C0

# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_img
{
	void	*img_to_draw;
	char	*addr_to_draw;
	void	*img_to_render;
	char	*addr_to_render;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*disp;
	void	*win;
}				t_mlx;

typedef struct s_coords
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}				t_coords;

typedef struct s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct s_player
{
	int		x;
	int		y;
	double	dy;
	double	dx;
	double	ang;
	char	viewdir;
	int		prnt_ray_info;
}				t_player;

typedef struct s_game
{
	t_mlx		mlx;
	t_color		ceiling;
	t_color		floor;
	t_coords	textures;
	t_img		images;
	bool		ready_for_map;
	t_player	player;
	char		**map;
}				t_game;

// print_err.c
int		print_err(const char *str, int ret);

// map_validations.c
int		ft_check_extension(const char *filename, const char *ext);

// exit.c
int		clean_exit(t_game *cub3d, const char *error, int error_nb);
void	clean_game_ptrs(t_game *cub3d);
void	*free_map(char **map);

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
void	*free_map(char **map);
void	free_images(t_img *images, void *disp);
void	free_coords(t_coords *textures);
void	free_mlx(t_mlx *mlx);

// draw_map.c
void	draw_map(t_game *cub3d);

// draw_player.c
void	draw_player(t_game *cub3d);

// draw_ray.c
void	draw_ray(t_game *cub3d);

// draw_tools.c
int		create_trgb(int t, int r, int g, int b);
void	put_pxl_on_img(t_img *images, int x, int y, int color);

// map_tools.c
int		is_ready_for_map(t_game *game);
void	validate_map(t_game *cub3d);

// moves.c
void	try_move_x(int key, t_game *cub3d);
void	try_move_y(int key, t_game *cub3d);
void	rotate(int key, t_player *ply);

// set_pllayer.c
void	set_player(t_game *cub3d);

// add_line_to_map.c
int		add_line_to_map(const char *line, t_game *cub3d);

// test.c
void	test(const t_game *cub3d);

// init.c
void	init_game(t_game *cub3d);

// init_structs.c
void	init_t_game(t_game *cub3d);

// switch_img.c
void	switch_img(t_img *images);

// create_image.c
void	create_image(t_game *cub3d);

// render.c
int		render(t_game *cub3d);

// switch_img.c
void	switch_img(t_img *images);

#endif
