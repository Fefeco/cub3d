/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:38 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/11 13:48:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"

int	extract_params(char **line_ref, t_game *cub3d)
{
	char	*line;
	int		ret;

	ret = 0;
	line = *line_ref;
	while (*line && (ft_isspace(*line) || *line == '\n'))
		++line;
	if (*line)
	{
		if (*line == 'N' || *line == 'S' || *line == 'W' || *line == 'E')
			ret = extract_coord(line, cub3d);
		else if (*line == 'F' || *line == 'C')
			ret = extract_color(line, cub3d);
		else if (ft_strchr("01NSEW", *line) && is_ready_for_map(cub3d))
			ret = add_line_to_map(*line_ref, cub3d);
		else
			ret = print_err("Instruction not allowed in map file", -1);
	}
	free (*line_ref);
	return (ret);
}
