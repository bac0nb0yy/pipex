/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:27:46 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 04:51:48 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	write_number(long number, int fd)
{
	char	digit;

	if (number == 0)
		return ;
	write_number(number / 10, fd);
	digit = number % 10 + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	number;

	number = (long)n;
	if (number == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (number < 0)
	{
		write(fd, "-", 1);
		number *= -1;
	}
	write_number(number, fd);
}
