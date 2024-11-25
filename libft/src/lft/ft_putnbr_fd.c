/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:04:07 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 19:09:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int		module;
	int		sign;
	char	c;

	c = '0';
	sign = 1;
	if (nb < 0)
	{
		write(fd, "-", 1);
		sign = -1;
	}
	if (nb < -9 || nb > 9)
	{
		ft_putnbr_fd((nb / 10) * sign, fd);
		module = (nb % 10) * sign;
	}
	else
		module = nb * sign;
	c += module;
	write(fd, &c, 1);
}
