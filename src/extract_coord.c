/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:24:18 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/28 16:23:46 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"
#include "libft.h"

static bool	set(char **param, char **value)
{
	if (*param)
	{
		print_err("To many declarations for the same coordinates", -1);
		free (*value);
		*value = NULL;
		return (false);
	}
	*param = *value;
	return (true);
}

static bool	set_coord(const char *tmp, const char *line, t_coords *textures)
{
	char	*value;

	value = ft_rmspaces(line);
	if (!value)
		return (false);
	if (!ft_strncmp(tmp, "NO", 3))
		return (set(&textures->NO, &value));
	else if (!ft_strncmp(tmp, "SO", 3))
		return (set(&textures->SO, &value));
	else if (!ft_strncmp(tmp, "WE", 3))
		return (set(&textures->WE, &value));
	else if (!ft_strncmp(tmp, "EA", 3))
		return (set(&textures->EA, &value));
	free (value);
	return (false);
}

int	extract_coord(char *line, t_game *cub3d)
{
	char		*tmp;
	bool		success;
	const char	*coords[] = {"NO", "SO", "WE", "EA", NULL};

	tmp = (char *)ft_calloc(3, sizeof(char));
	if (!tmp)
		return (print_err("Malloc failed!", -1));
	success = false;
	tmp[0] = *line++;
	while (ft_isspace(*line))
		++line;
	tmp[1] = *line++;
	if (ft_isspace(*line) && ft_strnarrcmp(tmp, coords, 3))
		success = set_coord(tmp, line, &cub3d->textures);
	free (tmp);
	if (success)
		return (0);
	return (print_err("Instruction not allowed in map file", -1));
}
