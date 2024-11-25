/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:13:54 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 14:49:57 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, size_t size)
{
	void	*ptr;
	int		total_size;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, total_size);
	return (ptr);
}
