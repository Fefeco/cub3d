/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:54:57 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/10 16:24:03 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		++len;
	while (nb != 0)
	{
		++len;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*str_nb;
	int		len;
	int		current_nb;

	len = int_len(nb);
	str_nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!str_nb)
		return (str_nb);
	str_nb[len] = '\0';
	if (nb < 0)
		str_nb[0] = '-';
	if (nb == 0)
		str_nb[0] = '0';
	while (nb != 0)
	{
		current_nb = nb % 10;
		if (current_nb < 0)
			current_nb *= -1;
		str_nb[--len] = '0' + current_nb;
		nb /= 10;
	}
	return (str_nb);
}
