/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:04:56 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 04:46:25 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

size_t	printf_strlen(char *str)
{
	register char	*s;

	if (!str)
		return (0);
	s = str;
	while (*s)
		++s;
	return (s - str);
}

void	last_digit(long long number, char *base, int *len)
{
	long long	k;

	k = number % printf_strlen(base);
	if (number != 0)
	{
		*len += 1;
		last_digit(number / printf_strlen(base), base, len);
		write(1, &base[k], 1);
	}
}
