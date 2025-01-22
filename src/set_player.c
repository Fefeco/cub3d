/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:57:33 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/22 22:29:13 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "libft.h"

static double	get_ang(char viewdir)
{
	if (viewdir == 'E')
		return (0);
	else if (viewdir == 'S')
		return (M_PI / 2);
	else if (viewdir == 'W')
		return (M_PI);
	else if (viewdir == 'N')
		return (3 * (M_PI / 2));
	return (-1);
}

static int	set_params(t_player *ply, char viewdir, int x, int y)
{
	if (ply->ang != -1)
		return (1);
	ply->pos.x = x * TILE + TILE / 2;
	ply->pos.y = y * TILE + TILE / 2;
	ply->ang = get_ang(viewdir);
	if (ply->ang == -1)
		return (1);
	return (0);
}

void	set_player(t_game *cub3d)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (cub3d->map[++y])
	{
		x = -1;
		while (cub3d->map[y][++x])
		{
			c = cub3d->map[y][x];
			if (ft_strchr("NSEW", c) && set_params(&cub3d->ply, c, x, y))
				break ;
		}
	}
	if (cub3d->map[y])
		clean_exit(cub3d, E_PTMSET, 4);
	if (cub3d->ply.ang == -1)
		clean_exit(cub3d, E_PNOSET, 4);
}
