/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/27 19:44:31 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	extract_coord(char *line, t_game *cub3d)
{
	char	*tmp;
	char	*value;

	tmp = (char *)ft_calloc(sizeof(char) * 3);
	if (!tmp)
	{
		print_err("Malloc failed!");
		return (-1);
	}
	*tmp = *line++;
	while (is_space(*line))
		++line;
	tmp[1] = *line++;
	if (!is_space(*line) || !is_coord(tmp))
	{
		print_err("Instruction not allowed in map file");
		return (-1)
	}
	return (0);
}

int	extract_params(char **line_ref, t_game *cub3d)
{
	char	*line;
	int		ret;

	ret = 0;
	line = *line_ref;
	while (*line && is_space(*line))
		++line;
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		ret = extract_coord(line, cub3d);		// Not implemented
	else if (*line == 'F' || *line == 'C')
		ret = extract_color(line, cub3d);		// Not implemented
	else if (*line == '1' || *line == '0')
		ret = extract_map(*line_ref, cub3d);	// Not implemented
	else
	{
		print_err("Instruction not allowed in map file");
		ret = -1;
	}
	free (*line_ref);
	*line_ref = NULL;
	return (ret);
}
