/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:24:18 by fcarranz          #+#    #+#             */
/*   Updated: 2025/01/31 11:30:26 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static bool	set(char **param, char **value)
{
	if (*param)
	{
		print_error(E_TMCOOR);
		free (*value);
		*value = NULL;
		return (false);
	}
	*param = *value;
	return (true);
}

static char	*rm_spaces_endl(const char *str)
{
	char	*tmp;
	char	*ret;

	tmp = ft_rmspaces(str);
	if (!tmp)
		return (NULL);
	ret = ft_strtrim(tmp, "\n");
	free (tmp);
	return (ret);
}

static bool	set_coord(const char *tmp, const char *line, t_tex *tex)
{
	char	*value;

	value = rm_spaces_endl(line);
	if (!value)
		return (false);
	if (!ft_strncmp(tmp, "NO", 3))
		return (set(&tex->file_no, &value));
	else if (!ft_strncmp(tmp, "SO", 3))
		return (set(&tex->file_so, &value));
	else if (!ft_strncmp(tmp, "WE", 3))
		return (set(&tex->file_we, &value));
	else if (!ft_strncmp(tmp, "EA", 3))
		return (set(&tex->file_ea, &value));
	free (value);
	return (false);
}

int	extract_coord(const char *line, t_game *cub3d)
{
	char		*tmp;
	bool		success;
	const char	*coords[] = {"NO", "SO", "WE", "EA", NULL};

	tmp = (char *)ft_calloc(3, sizeof(char));
	if (!tmp)
	{
		print_error(E_MALLOC);
		return (-1);
	}
	success = false;
	tmp[0] = *line++;
	while (*line && (ft_isspace(*line) || *line == '\n'))
		++line;
	if (*line)
	{
		tmp[1] = *line++;
		if (*line && ft_isspace(*line) && ft_strnarrcmp(tmp, coords, 3))
			success = set_coord(tmp, line, &cub3d->tex);
	}
	free (tmp);
	if (success)
		return (0);
	print_error(E_WINST);
	return (-1);
}
