/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:57:47 by davifer2          #+#    #+#             */
/*   Updated: 2024/10/24 21:04:38 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_error(char *str, int ret)
{
    write(2, str, strlen(str));
    return (ret);
}

int main(int argc, char **argv)
{
    (void)argv;
    if (argc < 2 || argc > 3)
        return (ft_error("Error\nInvalid number of arguments\n", 1));
    return (0);
}
