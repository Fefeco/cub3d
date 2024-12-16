/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:56:03 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/16 14:21:18 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	switch_img(t_img *images)
{
	void	*tmp_img;
	char	*tmp_addr;

	tmp_img = images->img_to_render;
	tmp_addr = images->addr_to_render;
	images->img_to_render = images->img_to_draw;
	images->addr_to_render = images->addr_to_draw;
	images->img_to_draw = tmp_img;
	images->addr_to_draw = tmp_addr;
}
