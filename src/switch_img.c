/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:56:03 by fcarranz          #+#    #+#             */
/*   Updated: 2025/02/01 11:38:43 by fedeito          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to change
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
// To
void	switch_iimg(t_iimg *img1, t_iimg *img2)
{
	t_iimg	tmp;

	tmp = *img1; 
	*img1 = *img2; 
	*img2 = tmp; 
}

// End
