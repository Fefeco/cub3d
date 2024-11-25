/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:11:34 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 20:17:45 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	total_len;

	total_len = 0;
	while (*dst && dst_size)
	{
		++dst;
		++total_len;
		--dst_size;
	}
	if (dst_size)
	{
		while (*src && --dst_size)
		{
			*dst++ = *src++;
			++total_len;
		}
		*dst = '\0';
	}
	while (*src++)
		++total_len;
	return (total_len);
}
