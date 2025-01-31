/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:41 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 13:40:48 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "error.h"

int	is_ready_for_map(t_game *game)
{
	t_tex	*tex;

	if (game->ready_for_map)
		return (1);
	tex = &game->tex;
	if (!tex->file_no || !tex->file_so || !tex->file_we || !tex->file_ea)
	{
		print_error(E_MTXPAR);
		return (0);
	}
	if (!color_ok(&game->ceiling) || !color_ok(&game->floor))
	{
		print_error(E_MCPAR);
		return (0);
	}
	game->ready_for_map = true;
	return (1);
}

static bool	is_space_arround(int x, int y, char **map)
{
	int	row;
	int	col;

	row = -2;
	while (row < 1)
	{
		++row;
		if (y + row < 0)
			continue ;
		if (!map[y + row])
			continue ;
		col = -2;
		while (col < 1)
		{
			++col;
			if (x + col < 0 || (row == 0 && col == 0))
				continue ;
			if (!map[y + row][x + col])
				continue ;
			if (map[y + row][x + col] == ' ')
				return (true);
		}
	}
	return (false);
}

void	validate_map(t_game *cub3d)
{
	char	*line;
	int		x;
	int		y;

	y = -1;
	while (cub3d->map[++y])
	{
		line = cub3d->map[y];
		x = -1;
		while (line[++x])
		{
			if (line[x] != '0' && !ft_strchr("NSEW", line[x]))
				continue ;
			if (is_space_arround(x, y, cub3d->map))
				clean_exit(cub3d, E_NOWALL, 5);
		}
	}
}
