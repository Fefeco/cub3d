/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:48:06 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/18 12:52:58 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_pxl_on_img(t_img *images, int x, int y, int color)
{
	char	*dst;

	dst = images->addr_to_draw + (y * images->line_length
			+ x * (images->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
