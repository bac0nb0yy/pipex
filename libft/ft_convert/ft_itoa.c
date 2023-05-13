/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 02:30:19 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:21:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	number_of_digits(long number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		i++;
		number /= 10;
	}
	return (i);
}

static	char	*result(int sign, int digits, long number)
{
	char	*result;
	int		size_malloc;

	size_malloc = digits + (sign == 0) + 1;
	result = malloc(size_malloc);
	if (!result)
		return (NULL);
	if (sign == 0)
		result[0] = '-';
	while (digits)
	{
		result[digits - sign] = (number % 10) + '0';
		number = number / 10;
		digits--;
	}
	result[size_malloc - 1] = 0;
	return (result);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	long	number;

	number = (long)n;
	sign = 1 * (number >= 0);
	if (number < 0)
		number = -number;
	digits = number_of_digits(number);
	return (result(sign, digits, number));
}
