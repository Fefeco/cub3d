/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_deltas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:45:17 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/06 10:51:05 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static bool	is_close(double a, double b)
{
	return (fabs(a - b) < EPSILON);
}

void	set_deltas(t_dvec *delta, double ang)
{
	if (is_close(ang, 0) || is_close(ang, 2 * M_PI))
	{
		delta->x = 1;
		delta->y = 0;
	}
	else if (is_close(ang, M_PI / 2))
	{
		delta->x = 0;
		delta->y = 1;
	}
	else if (is_close(ang, M_PI))
	{
		delta->x = -1;
		delta->y = 0;
	}
	else if (is_close(ang, 3 * M_PI / 2))
	{
		delta->x = 0;
		delta->y = -1;
	}
	else
	{
		delta->x = cos(ang);
		delta->y = sin(ang);
	}
}
