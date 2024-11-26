/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:21:49 by davifer2          #+#    #+#             */
/*   Updated: 2024/11/26 13:16:31 by fcarranz         ###   ########.fr       */
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


int		print_err(const char *str, int ret);
int		ft_check_extension(const char *filename, const char *ext);
int		exit_err(const char *error, int ret);
void	set_game_params(char *filename);

#endif
