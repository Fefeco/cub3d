/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:46:36 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/11 13:49:18 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void set_vector_directions(t_ivec *vec_dir, t_dvec delta)
{
	if (delta.x < 0)
		vec_dir->x = -1;
	else if (delta.x == 0)
		vec_dir->x = 0;
	else
		vec_dir->x = 1;
	if (delta.y < 0)
		vec_dir->y = -1;
	else if (delta.y == 0)
		vec_dir->y = 0;
	else
		vec_dir->y = 1;
}

bool is_close(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

// Función para manejar los ángulos especiales
void set_deltas(t_dvec *delta, double ang) {
    if (is_close(ang, 0) || is_close(ang, 2 * M_PI)) {
        delta->x = 1;
        delta->y = 0;
    } else if (is_close(ang, M_PI / 2)) {
        delta->x = 0;
        delta->y = 1;
    } else if (is_close(ang, M_PI)) {
        delta->x = -1;
        delta->y = 0;
    } else if (is_close(ang, 3 * M_PI / 2)) {
        delta->x = 0;
        delta->y = -1;
    } else {
        // Para ángulos generales, usa las funciones trigonométricas
        delta->x = cos(ang);
        delta->y = sin(ang);
    }
}

void	set_delta_dists(t_dvec *delta_dist, t_dvec delta)
{
	if (delta.x == 0)
		delta_dist->x = 0;
	else
		delta_dist->x = fabs(TILE / delta.x);
	if (delta.y == 0)
		delta_dist->y = 0;
	else
		delta_dist->y = fabs(TILE / delta.y);
}

t_ivec	get_map_coords(t_ivec ply_pos)
{
	t_ivec	map_pt;

	map_pt.x = ply_pos.x / TILE;
	map_pt.y = ply_pos.y / TILE;
	return (map_pt);
}

t_dvec	calc_first_travel_dist(t_ivec vec_dir, t_ivec ply_pos, t_dvec delta)
{
	t_dvec	travel_dist;

	if (vec_dir.x > 0)
		travel_dist.x = (TILE - (ply_pos.x % TILE));
	else
		travel_dist.x = (ply_pos.x % TILE);
	if (vec_dir.y > 0)
		travel_dist.y = (TILE - (ply_pos.y % TILE));
	else
		travel_dist.y = (ply_pos.y % TILE);
	travel_dist.x /= delta.x;
	travel_dist.y = delta.y;
	return (travel_dist);
}

int	calc_steps(t_dvec travel_dist, t_dvec delta)
{
	if (!travel_dist.y || (travel_dist.x && travel_dist.x < travel_dist.y))
		return fabs(travel_dist.x / delta.x);
	return fabs(travel_dist.y / delta.y);
}

double	get_steps(t_ivec ply_pos, double ang, char **map)
{
	t_dvec	delta;
	t_dvec	delta_dist;
	t_dvec	travel_dist;
	t_ivec	vec_dir;
	t_ivec	map_pos;
	char	flag;

	flag = '0';
	set_deltas(&delta, ang);
	set_vector_directions(&vec_dir, delta);
	set_delta_dists(&delta_dist, delta);
	map_pos = get_map_coords(ply_pos);
	travel_dist = calc_first_travel_dist(vec_dir, ply_pos, delta);
	while (1)
	{
		if (!delta_dist.y || (delta_dist.x && travel_dist.x < travel_dist.y))
		{
			flag = 'x';
			map_pos.x += vec_dir.x;
		}
		else
		{
			flag = 'y';
			map_pos.y += vec_dir.y;
		}
		if (check_wall(map_pos.x, map_pos.y, map))
			break ;
		if (flag == 'x')
			travel_dist.x += delta_dist.x;
		else
			travel_dist.y += delta_dist.y;
	}
	return (calc_steps(travel_dist, delta)); 
}
