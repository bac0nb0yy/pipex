/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:15:25 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:32:25 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s) > len + start)
		i = len;
	else
		i = ft_strlen(s) - start;
	tmp = malloc(i + 1);
	if (!tmp)
		return (NULL);
	tmp = ft_memcpy(tmp, s + start, i);
	tmp[i] = 0;
	return (tmp);
}
