/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:30:47 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 18:12:55 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*u_src;
	unsigned char		*u_dst;

	u_dst = (unsigned char *) dst;
	u_src = (const unsigned char *) src;
	if (src < dst)
	{
		u_dst += len - 1;
		u_src += len - 1;
		while (len--)
			*u_dst-- = *u_src--;
	}
	else if (src > dst)
	{
		while (len--)
			*u_dst++ = *u_src++;
	}
	return (dst);
}
