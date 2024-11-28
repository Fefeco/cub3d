/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:24:18 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/28 13:52:21 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

static bool	set_coord(const char *tmp, const char *line, t_coords *textures)
{
	char	*value;

	value = ft_rmspaces(line);
	if (!ft_strncmp(tmp, "NO", 3) && !textures->NO)
		textures->NO = value;
	else if (!ft_strncmp(tmp, "SO", 3) && !textures->SO)
		textures->SO = value;
	else if (!ft_strncmp(tmp, "WE", 3) && !textures->WE)
		textures->WE = value;
	else if (!ft_strncmp(tmp, "EA", 3) && !textures->EA)
		textures->EA = value;
	return (true);
}

int	extract_coord(char *line, t_game *cub3d)
{
	char		*tmp;
	bool		success;
	const char	**coords = {"NO", "SO", "WE", "EA", NULL};

	tmp = (char *)ft_calloc(sizeof(char) * 3);
	if (!tmp)
	{
		print_err("Malloc failed!");
		return (-1);
	}
	success = false;
	tmp[0] = *line++;
	while (is_space(*line))
		++line;
	tmp[1] = *line++;
	if (is_space(*line) && ft_strnarrcmp(tmp, coords, 3))
		success = set_coord(tmp, line, &cub3d->textures);
	free (tmp);
	if (success)
		return (0);
	print_err("Instruction not allowed in map file");
	return (-1);
}
