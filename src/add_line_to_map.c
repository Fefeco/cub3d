/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line_to_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:23 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/11 14:45:44 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

static char	**append_line(char **map, const char *map_line)
{
	size_t	size;
	char	**new_array;

	size = ft_array_size((const char **)map);
	new_array = (char **)malloc(sizeof(char *) * (size + 2));
	if (!new_array)
		return (NULL);
	new_array[size + 1] = NULL;
	new_array[size] = (char *)map_line;
	while (size--)
		new_array[size] = map[size];
	return (new_array);
}

static int	invalid_char(const char *line)
{
	while (*line)
	{
		if (ft_strchr(" 01NSEW", *line++) == NULL)
			return (print_err("Invalid character in map", 1));
	}
	return (0);
}

int add_line_to_map(const char *line, t_game *cub3d)
{
	char	**map;
	char	*map_line;

	map_line = ft_strtrim(line, "\n");
	if (map_line && !invalid_char(map_line))
	{
		map = append_line(cub3d->map, map_line);
		if (map)
		{

			free (cub3d->map);
			cub3d->map = map;
			return (0);
		}
	}
	if (map_line)
		free(map_line);
	cub3d->map = free_map(cub3d->map);
	return (-1);
}
