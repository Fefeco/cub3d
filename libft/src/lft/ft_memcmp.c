/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:00:03 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 17:30:36 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *str1, const void *str2, int size)
{
	unsigned char	*u_str1;
	unsigned char	*u_str2;
	int				diff;

	u_str1 = (unsigned char *)str1;
	u_str2 = (unsigned char *)str2;
	while (size--)
	{
		diff = *u_str1++ - *u_str2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
