/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:21:49 by davifer2          #+#    #+#             */
/*   Updated: 2024/12/10 13:43:13 by fcarranz         ###   ########.fr       */
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

typedef struct	s_coords
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
}				t_coords;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_game
{
	t_color		ceiling;
	t_color		floor;
	t_coords	textures;
	bool		ready_for_map;
	char		**map;
}				t_game;

// print_err.c
int		print_err(const char *str, int ret);

// map_validations.c
int		ft_check_extension(const char *filename, const char *ext);


// main.c
void	init_t_game_ptrs(t_game *cub3d);

// exit.c
int		exit_err(const char *error, int ret);
void	free_t_game_ptrs(t_game *cub3d);
void	*free_map(char **map);

// set_params.c
void	set_game_params(char *filename, t_game *cub3d);

// extract.c
int		extract_params(char **line_ref, t_game *cub3d);

// extract_coord.c
int		extract_coord(const char *line, t_game *cub3d);

// extract_color.c
int		extract_color(const char *line, t_game *cub3d);
bool    color_ok(t_color *color);

// map_tools.c
int 	is_ready_for_map(t_game *game);

// add_line_to_map.c
int 	add_line_to_map(const char *line, t_game *cub3d);

// test.c
void	test(const t_game *cub3d);

#endif
