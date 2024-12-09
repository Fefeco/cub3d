/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:58:23 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/09 13:37:06 by fcarranz         ###   ########.fr       */
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

int extract_map(char *line, t_game *cub3d)
{
	// Implement map extraction
	return (0);
}