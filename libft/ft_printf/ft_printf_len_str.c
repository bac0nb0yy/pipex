/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 04:48:18 by dtelnov           #+#    #+#             */
/*   Updated: 2023/06/28 03:48:47 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strarglen(char *s)
{
	int		len;

	if (!s)
		return (6);
	len = 0;
	while (s[len])
		++len;
	return (len);
}
