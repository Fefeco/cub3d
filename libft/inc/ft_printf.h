/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:02:15 by davifer2          #+#    #+#             */
/*   Updated: 2024/11/27 10:13:25 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printf(char const *str, ...);
int		ft_printchar_fd(char c, int fd);
int		ft_printstr_fd(char *s, int fd);
int		ft_printnbr_fd(int n, int fd);
int		ft_printnbrunsig_fd(unsigned int n, int fd);
int		ft_printhex_fd(unsigned long long n, int fd, char format);
size_t	ft_nbrlen(int n);
size_t	ft_hexlen(unsigned long long nbr, char format);
size_t	ft_nbrunsiglen(unsigned int nb);

#endif
