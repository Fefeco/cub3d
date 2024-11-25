/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:28:13 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 17:43:54 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	const unsigned char	*u_src;
	unsigned char		*u_dst;

	if (!dst && !src)
		return (dst);
	u_src = (const unsigned char *)src;
	u_dst = (unsigned char *)dst;
	while (len--)
		*u_dst++ = *u_src++;
	return (dst);
}
