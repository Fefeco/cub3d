/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:49:15 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/27 12:27:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static bool is_close(double a, double b)
{
	return fabs(a - b) < EPSILON;
}

// Función para manejar los ángulos especiales
void set_deltas(t_dvec *delta, double ang)
{
	if (is_close(ang, 0) || is_close(ang, 2 * M_PI))
	{
		delta->x = 1;
		delta->y = 0;
	} else if (is_close(ang, M_PI / 2))
	{
		delta->x = 0;
		delta->y = 1;
	} else if (is_close(ang, M_PI))
	{
		delta->x = -1;
		delta->y = 0;
	} else if (is_close(ang, 3 * M_PI / 2))
	{
		delta->x = 0;
		delta->y = -1;
	} else
	{
		// Para ángulos generales, usa las funciones trigonométricas
		delta->x = cos(ang);
		delta->y = sin(ang);
	}
}

int	check_wall(int x, int y, char **map)
{
	if (!map || map[y][x] == '1')
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
