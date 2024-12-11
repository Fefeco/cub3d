/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/11 19:29:11 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int is_ready_for_map(t_game *game)
{
	t_coords *text;

	if (game->ready_for_map)
		return (1);
	text = &game->textures;
	if (!text->NO || !text->SO || !text->WE || !text->EA)
		return (print_err("Missing texture parameters before map", 0));
	if (!color_ok(&game->ceiling) || !color_ok(&game->floor))
		return (print_err("Missing color parameters before map", 0));
	game->ready_for_map = true;
	return (1);
}

static int	find_orientation(char *line)
{	
	int	found;

	if (!line)
		return (0);
	found = 0;
	while (*line)
	{
		if (ft_strchr("NSEW", *line))
		{
			if (found)
				found = -1;
			else
				found = *line;
		}
		++line;
	}
	return (found);
}

void	set_player_orient(t_game *cub3d)
{
	char	**map;
	char	*line;
	char	found;

	map = cub3d->map;
	while (map && *map)
	{
		line = *map;
		found = find_orientation(line);
		if (found == -1 || (found > 0 && cub3d->player_orient > 0))
			break ;
		if (found > 0)
			cub3d->player_orient = found;
		found = 0;
		++map;
	}
	if (cub3d->player_orient && !found)
		return ;
	if (!cub3d->player_orient)
		print_err("Payer orientation not set", 1);
	else
		print_err("Payer orientation set more than once", 1);
	free_t_game_ptrs(cub3d);
	exit(EXIT_FAILURE);
}

static bool	is_space_arround(int x, int y, char **map)
{
	int	row;
	int	col;

	row = -2;
	while (row < 1)
	{
		++row;
		if (x + row < 0)
			continue ;
		if (!map[x + row])
			continue ;
		col = -2;
		while (col < 1)
		{
			++col;
			if (y + col < 0 || (row == 0 && col == 0))
				continue ;
			if (!map[y + col])
				continue ;
			if (map[x + row][y + col] == ' ')
				return (false);
		}
	}
	return (true);
}

void	validate_map(t_game *cub3d)
{
	char	*tmp_line;
	int		x;
	int		y;

	total_lines = ft_array_size(map);
	x = 0;
	while (map[x])
	{
		tmp_line = map[x++];
		y = 0;
		while (tmp_line[y])
		{
			if (*tmp_line != ' ' && *tmp_line != '1')
			{
				if (*tmp_line != '0' && cub3d->player_orient != -1)
					cub3d->player_orient = *tmp_line;
				else
					print_err("Too may declaratios for player position");
			}
				return (-1);
			++y;
		}
	}

}
