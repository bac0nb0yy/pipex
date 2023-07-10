/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:14:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/06/28 01:47:51 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arglen(const char *s, va_list args)
{
	char	format;
	int		len;

	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			format = *(++s);
			if (format == 'c')
				va_arg(args, int);
			if (format == '%' || format == 'c')
				++len;
			else if (format == 's')
				len += ft_strarglen(va_arg(args, char *));
			else
				len += calculate_len(args, format);
		}
		else
			++len;
		++s;
	}
	return (len);
}

char	*ft_argjoin(const char *s, va_list args, int size_malloc)
{
	char	*to_print;
	char	format;
	int		index;

	to_print = malloc(size_malloc);
	if (!to_print)
		return (NULL);
	index = 0;
	while (*s)
	{
		if (*s == '%')
		{
			format = *(++s);
			convert_args(args, format, to_print, &index);
		}
		else
			to_print[index++] = *s;
		++s;
	}
	to_print[index] = 0;
	return (to_print);
}

char	*ft_sprintf(const char *s, va_list args, va_list args_bis)
{
	char	*to_print;
	int		size_malloc;

	size_malloc = ft_arglen(s, args) + 1;
	to_print = ft_argjoin(s, args_bis, size_malloc);
	return (to_print);
}

int	ft_dprintf(int fd, const char *s, ...)
{
	va_list	args;
	va_list	args_bis;
	va_list	args_third;
	char	*display;
	int		ret;

	va_start(args, s);
	va_start(args_bis, s);
	display = ft_sprintf(s, args, args_bis);
	if (!display)
		return (va_end(args), va_end(args_bis), -1);
	va_end(args);
	va_end(args_bis);
	va_start(args_third, s);
	ret = ft_arglen(s, args_third);
	va_end(args_third);
	write(fd, display, ret);
	free(display);
	return (ret);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	va_list	args_bis;
	va_list	args_third;
	char	*display;
	int		ret;

	va_start(args, s);
	va_start(args_bis, s);
	display = ft_sprintf(s, args, args_bis);
	if (!display)
		return (va_end(args), va_end(args_bis), -1);
	va_end(args);
	va_end(args_bis);
	va_start(args_third, s);
	ret = ft_arglen(s, args_third);
	va_end(args_third);
	write(1, display, ret);
	free(display);
	return (ret);
}
