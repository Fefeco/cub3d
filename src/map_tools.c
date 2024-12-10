/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:17:41 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/10 12:39:24 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

/*int	check_map(char **map)
{
	char	*tmp_line;

	if (!map)
		return (-1);


}*/
