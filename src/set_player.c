/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedeito <fcarranz@student.42barcel>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:57:33 by fedeito           #+#    #+#             */
/*   Updated: 2025/01/16 18:15:42 by fedeito          ###   ########.fr       */
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

static int	set_params(t_player *player, char viewdir, int x, int y)
{
	if (player->ang != -1)
		return (1);
	player->x = x * TILE + TILE / 2;
	player->y = y * TILE + TILE / 2;
	player->ang = get_ang(viewdir);
	if (player->ang == -1)
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
			if (ft_strchr("NSEW", c) && set_params(&cub3d->player, c, x, y))
				break ;
		}
	}
	if (cub3d->map[y])
		clean_exit(cub3d, E_PTMSET, 4);
	if (cub3d->player.ang == -1)
		clean_exit(cub3d, E_PNOSET, 4);
}
