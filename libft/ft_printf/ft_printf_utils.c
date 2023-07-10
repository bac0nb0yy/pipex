/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:48:44 by dtelnov           #+#    #+#             */
/*   Updated: 2023/06/28 03:48:40 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hexa_converter_ul(va_list arg, char *to_fill, int *index)
{
	const char		*nil_str = "(nil)";
	int				len_result;
	unsigned long	to_convert;
	int				i;

	to_convert = va_arg(arg, unsigned long);
	len_result = ft_ullen(to_convert, 16);
	if (len_result == 5)
	{
		i = 0;
		while (i < 5)
			to_fill[(*index)++] = nil_str[i++];
		return ;
	}
	to_fill[*index] = '0';
	to_fill[*index + 1] = 'x';
	i = len_result - 1;
	while (i >= 2)
	{
		to_fill[*index + i] = HEX_LOWER_VALUES[to_convert % 16];
		to_convert /= 16;
		--i;
	}
	*index += len_result;
}

void	hexa_converter_uint(va_list arg, char *to_fill, int *index, char format)
{
	int				len_result;
	unsigned int	to_convert;
	int				i;

	to_convert = va_arg(arg, unsigned int);
	len_result = ft_uintlen(to_convert, 16);
	i = len_result - 1;
	while (i >= 0)
	{
		if (format == 'x')
			to_fill[*index + i] = HEX_LOWER_VALUES[to_convert % 16];
		else
			to_fill[*index + i] = HEX_UPPER_VALUES[to_convert % 16];
		to_convert /= 16;
		--i;
	}
	*index += len_result;
}

void	convert_args(va_list args, char format, char *to_print, int *index)
{
	if (format == '%')
		to_print[(*index)++] = '%';
	else if (format == 'c')
		add_char(args, to_print, index);
	else if (format == 's')
		add_str(va_arg(args, char *), to_print, index);
	else if (format == 'p')
		hexa_converter_ul(args, to_print, index);
	else if (format == 'd' || format == 'i')
		add_nbr_int(args, to_print, index);
	else if (format == 'u')
		add_nbr_uint(args, to_print, index);
	else if (format == 'x' || format == 'X')
		hexa_converter_uint(args, to_print, index, format);
}
