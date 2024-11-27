/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:21:49 by davifer2          #+#    #+#             */
/*   Updated: 2024/11/27 16:33:19 by fcarranz         ###   ########.fr       */
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
	char	*rgb;
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_game
{
	t_color		ceiling;
	t_color		floor;
	t_coords	textures;
	char		*map;
}				t_game;

// print_err.c
int		print_err(const char *str, int ret);

// map_validations.c
int		ft_check_extension(const char *filename, const char *ext);

// exit.c
int		exit_err(const char *error, int ret);
void	free_t_game_params(t_game *cub3d);

// set_params.c
void	set_game_params(char *filename, t_game *cub3d);

#endif
