/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 02:00:57 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/21 04:46:27 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(char format, va_list parameters, int *len)
{
	static int	(*f[])(va_list) = {hdl_c, hdl_s, hdl_p, hdl_d_i, hdl_d_i, hdl_u,
		hdl_x, hdl_x_uppercase};
	const int	index_format = ft_strchr(SET_CONV, format) - SET_CONV;
	int			ret;

	ret = f[index_format](parameters);
	if (ret == -1)
		return (-1);
	*len += ret;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	char	format;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			format = s[++i];
			if (format == '%')
				printf_putchar('%', &len);
			else if (conversion(format, args, &len) == -1)
				return (-1);
		}
		else
			printf_putchar(s[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
