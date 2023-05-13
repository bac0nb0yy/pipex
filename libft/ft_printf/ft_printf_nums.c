/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:05:35 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 18:29:39 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hdl_d_i(va_list args)
{
	long long	number;
	int			len;

	len = 0;
	number = va_arg(args, int);
	if (number == 0)
	{
		write(1, &BASE_DECIMAL[0], 1);
		return (1);
	}
	else if (number < 0)
	{
		write(1, "-", 1);
		last_digit(-number, BASE_DECIMAL, &len);
		len++;
	}
	else
		last_digit(number, BASE_DECIMAL, &len);
	return (len);
}

int	hdl_u(va_list args)
{
	long long	number;
	int			len;

	len = 0;
	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		write(1, &BASE_DECIMAL[0], 1);
		return (1);
	}
	else if (number < 0)
	{
		write(1, "-", 1);
		last_digit(-number, BASE_DECIMAL, &len);
		len++;
	}
	else
		last_digit(number, BASE_DECIMAL, &len);
	return (len);
}

int	hdl_x(va_list args)
{
	unsigned int	number;
	int				len;

	len = 0;
	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		write(1, &HEXVALUES_LOWERCASE[0], 1);
		return (1);
	}
	else
		last_digit(number, HEXVALUES_LOWERCASE, &len);
	return (len);
}

int	hdl_x_uppercase(va_list args)
{
	unsigned int	number;
	int				len;

	len = 0;
	number = va_arg(args, unsigned int);
	if (number == 0)
	{
		write(1, &HEXVALUES_UPPERCASE[0], 1);
		return (1);
	}
	else
		last_digit(number, HEXVALUES_UPPERCASE, &len);
	return (len);
}

int	hdl_p(va_list args)
{
	unsigned long	ull_addr;
	char			tab[16];
	int				i;
	int				len;

	ull_addr = va_arg(args, unsigned long);
	if (ull_addr == 0)
		return (write(1, "(nil)", 5));
	i = 0;
	while (ull_addr > 0)
	{
		tab[i] = HEXVALUES_LOWERCASE[ull_addr % 16];
		ull_addr /= 16;
		i++;
	}
	write(1, "0x", 2);
	len = i + 2;
	i--;
	while (i >= 0)
	{
		if (write(1, &tab[i], 1) == -1)
			return (-1);
		i--;
	}
	return (len);
}
