/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:41 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 15:18:53 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "error.h"

bool	extract_line_to_map(char *line, t_game *cub3d)
{
	char	*tmp;

	tmp = line;
	while (*tmp && (ft_isspace(*tmp) || *tmp == '\n'))
		++tmp;
	if (!*tmp)
	{
		free(line);
		return (true);
	}
	else if (ft_strchr("01", *tmp))
		add_line_to_map((const char *)line, cub3d);
	free(line);
	return (false);
}

int	is_ready_for_map(t_game *cub)
{
	if (!cub->no.file || !cub->so.file || !cub->we.file || !cub->ea.file)
	{
		print_error(E_MTXPAR, cub);
		return (0);
	}
	if (!color_ok(&cub->ceiling) || !color_ok(&cub->floor))
	{
		print_error(E_MCPAR, cub);
		return (0);
	}
	cub->ready_for_map = true;
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
			return (true);
		if (!map[y + row])
			return (true);
		col = -2;
		while (col < 1)
		{
			++col;
			if (x + col < 0 || (row == 0 && col == 0))
				continue ;
			if (!map[y + row][x + col] || map[y + row][x + col] == ' ')
				return (true);
		}
	}
	return (false);
}

void	check_params_map(char *line, int y, t_game *cub3d, bool *ply)
{
	int		x;

	x = -1;
	while (line[++x])
	{
		if (line[x] != '0' && !ft_strchr("NSEW", line[x]))
			continue ;
		if (is_space_arround(x, y, cub3d->map))
			clean_exit(cub3d, E_NOWALL, 5);
		if (line[x] != '0' && !*ply)
			*ply = true;
		else if (line[x] != '0')
			clean_exit(cub3d, E_PTMSET, 5);
	}
}

void	validate_map(t_game *cub3d)
{
	char	*line;
	int		y;
	bool	ply;

	ply = false;
	y = -1;
	while (cub3d->map[++y])
	{
		line = cub3d->map[y];
		if (line && !ft_strchr(" 1", *line))
			clean_exit(cub3d, E_NOWALL, 5);
		check_params_map(line, y, cub3d, &ply);
	}
	if (!ply)
		clean_exit(cub3d, E_PNOSET, 4);
}
