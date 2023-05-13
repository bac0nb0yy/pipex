/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:31:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 04:47:53 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# define BASE_DECIMAL "0123456789"
# define SET_CONV "cspdiuxX"
# define HEXVALUES_LOWERCASE "0123456789abcdef"
# define HEXVALUES_UPPERCASE "0123456789ABCDEF"

size_t	printf_strlen(char *str);
void	printf_putchar(char c, int *len);
void	last_digit(long long number, char *base, int *len);
int		check_doublon(char *base, int index);
int		check_base(char *base);
int		hdl_d_i(va_list args);
int		hdl_c(va_list args);
int		hdl_s(va_list args);
int		hdl_p(va_list args);
int		hdl_u(va_list args);
int		hdl_x(va_list args);
int		hdl_x_uppercase(va_list args);
int		conversion(char format, va_list parameters, int *len);
int		ft_printf(const char *s, ...);

#endif
