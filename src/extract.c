/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/11/27 19:04:45 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	extract_params(char **line_ref, t_game *cub3d)
{
	char	*line;
	int		ret;

	ret = 0;
	line = *line_ref;
	while (*line && is_space(*line))
		++line;
	if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
		ret = extract_coord(line, cub3d);
	else if (*line == 'F' || *line == 'C')
		ret = extract_color(line, cub3d);
	else if (*line == '1' || *line == '0')
		ret = extract_map(*line_ref, cub3d);
	else
	{
		print_err("Instruction not allowed in map file");
		ret = -1;
	}
	free (*line_ref);
	*line_ref = NULL;
	return (ret);
}
