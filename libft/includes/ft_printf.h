/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:26:00 by dtelnov           #+#    #+#             */
/*   Updated: 2023/06/28 03:52:17 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>

# include "libft.h"

# define INT_CONV			"pdiuxX"
# define HEX_UPPER_VALUES	"0123456789ABCDEF"
# define HEX_LOWER_VALUES	"0123456789abcdef"
# define DEC_VALUES			"0123456789"

int		ft_intlen(int number, int base);
int		ft_uintlen(unsigned int number, int base);
int		ft_ullen(unsigned long number, int base);
int		calculate_len(va_list args, char format);
int		ft_arglen(const char *s, va_list args);
int		ft_strarglen(char *s);
void	convert_args(va_list args, char format, char *to_print, int *index);
char	*ft_sprintf(const char *s, va_list args, va_list args_bis);
char	*ft_argjoin(const char *s, va_list args, int size_malloc);
void	add_str(char *to_add, char *to_fill, int *index);
void	add_char(va_list arg, char *to_fill, int *index);
void	add_nbr_int(va_list arg, char *to_fill, int *index);
void	add_nbr_uint(va_list arg, char *to_fill, int *index);
void	hexa_converter_ul(va_list arg, char *to_fill, int *index);
void	hexa_converter_uint(va_list arg, char *to_fill,
			int *index, char format);
int		ft_printf(const char *s, ...);
int		ft_dprintf(int fd, const char *s, ...);
#endif