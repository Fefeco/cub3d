/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:49:15 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/28 20:51:49 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double deg_to_rad(int deg)
{
    return deg * (M_PI / 180.0);
}

int rad_to_deg(double rad)
{
    return (int)(rad * (180.0 / M_PI));
} 
