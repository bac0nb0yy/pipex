/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:17:05 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:29:31 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	i = 0;
	if (d_len >= size)
		return (size + s_len);
	while (src[i] && (i < size - d_len - 1))
	{
		dst[d_len + i] = src[i];
		++i;
	}
	dst[d_len + i] = 0;
	return (d_len + s_len);
}
