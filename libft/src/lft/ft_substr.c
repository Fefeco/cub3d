/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:21:25 by fcarranz          #+#    #+#             */
/*   Updated: 2024/10/15 12:02:59 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	src_len;

	src_len = ft_strlen(s);
	if (src_len < start)
	{
		len = 0;
		start = 0;
	}
	else if (len > src_len - start)
		len = src_len - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (!new_str)
		return (new_str);
	ft_strlcpy(new_str, s + start, len + 1);
	return (new_str);
}
