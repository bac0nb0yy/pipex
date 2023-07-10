/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:31:54 by dtelnov           #+#    #+#             */
/*   Updated: 2023/06/28 01:47:52 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_str(char *to_add, char *to_fill, int *index)
{
	const char	*null_str = "(null)";
	int			len_str;
	int			i;

	i = 0;
	if (to_add == NULL)
	{
		len_str = ft_strlen((char *)null_str);
		while (i < len_str)
		{
			to_fill[*index] = null_str[i];
			++*index;
			++i;
		}
		return ;
	}
	len_str = ft_strlen(to_add);
	while (i < len_str)
	{
		to_fill[*index] = to_add[i];
		++*index;
		++i;
	}
}

void	add_char(va_list arg, char *to_fill, int *index)
{
	unsigned char	to_add;

	to_add = va_arg(arg, int);
	to_fill[*index] = (unsigned char) to_add;
	*index += 1;
}

void	add_nbr_int(va_list arg, char *to_fill, int *index)
{
	int	len_result;
	int	to_convert;
	int	i;
	int	sign;

	to_convert = va_arg(arg, int);
	len_result = ft_intlen(to_convert, 10);
	sign = to_convert < 0;
	i = len_result - 1;
	if (sign == 1)
	{
		to_fill[*index] = '-';
		if (to_convert == INT_MIN)
			return (add_str("-2147483648", to_fill, index));
		to_convert = -to_convert;
	}
	while (i >= sign)
	{
		to_fill[*index + i] = DEC_VALUES[to_convert % 10];
		to_convert /= 10;
		--i;
	}
	*index += len_result;
}

void	add_nbr_uint(va_list arg, char *to_fill, int *index)
{
	int				len_result;
	unsigned int	to_convert;
	int				i;

	to_convert = va_arg(arg, unsigned int);
	len_result = ft_uintlen(to_convert, 10);
	i = len_result - 1;
	while (i >= 0)
	{
		to_fill[*index + i] = DEC_VALUES[to_convert % 10];
		to_convert /= 10;
		--i;
	}
	*index += len_result;
}
