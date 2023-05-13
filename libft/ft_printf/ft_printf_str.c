/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 08:06:45 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 04:46:22 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hdl_c(va_list args)
{
	unsigned char	character;

	character = va_arg(args, int);
	if (write(1, &character, 1) == -1)
		return (-1);
	return (1);
}

int	hdl_s(va_list args)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = printf_strlen(str);
	if (write(1, str, len) == -1)
		return (-1);
	return (len);
}
