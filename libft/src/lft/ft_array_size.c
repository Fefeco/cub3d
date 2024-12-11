/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:05:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/10 13:13:30 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_array_size(const char **array)
{
	size_t	size;

	size = 0;
	while (array && *array++)
		++size;
	return (size);
}
