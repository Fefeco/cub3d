/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:49:15 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/29 19:09:47 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

int	check_wall(int x, int y, char **map)
{
	if (!map || map[y / TILE][x / TILE] == '1')
		return (1);
	return (0);
}

double	norm_ang(double ang)
{
    if (ang < 0)
        ang += 2 * M_PI;
    if (ang >= 2 * M_PI)
        ang -= 2 * M_PI;
    return ang;
}

double deg_to_rad(int deg)
{
    return deg * (M_PI / 180.0);
}

int rad_to_deg(double rad)
{
    return (int)(rad * (180.0 / M_PI));
} 
