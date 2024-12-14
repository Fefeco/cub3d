/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:27:14 by fcarranz          #+#    #+#             */
/*   Updated: 2024/12/14 21:53:06 by fcarranz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define E_MALLOC	"Malloc failed"
# define E_WARGS	"Invalid number of arguments"
# define E_WCHAR	"Invalid character in map"
# define E_WINST	"Instruction not allowed in map file"
# define E_TMCOL	"Too many declarations for color parameter"
# define E_WCOLOR	"Wrong color format"
# define E_TMCOOR	"Too many declarations for the same coordinates"
# define E_MTXPAR	"Missing texture parameters before map"
# define E_MCPAR	"Missing color parameters before map"
# define E_PNOSET	"Payer orientation not set"
# define E_PTMSET	"Payer orientation set more than once"
# define E_NOWALL	"Map is not surrounded by walls"
# define E_WEXT		"Invalid extension"
# define E_UPARAM	"Uncomplete game parameters"

void	print_error(const char *error);

#endif
