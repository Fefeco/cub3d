/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:38 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/08 10:38:55 by fcarranz         ###   ########.fr       */
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
			ret = extract_coord(line, cub3d, *line_ref);
		else if (*line == 'F' || *line == 'C')
			ret = extract_color(line, cub3d);
		else if (ft_strchr("01", *line) && is_ready_for_map(cub3d))
			ret = add_line_to_map(*line_ref, cub3d);
		else
		{
			free (*line_ref);
			clean_exit(cub3d, E_WINST, 9);
		}
	}
	free (*line_ref);
	return (ret);
}
