/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:48:55 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:35:10 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len2;
	char	*tmp;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = malloc(len + len2 + 1);
	if (!tmp)
		return (NULL);
	len2 = 0;
	i = 0;
	while (s1[i])
		tmp[len2++] = s1[i++];
	i = 0;
	while (s2[i])
		tmp[len2++] = s2[i++];
	tmp[len2] = 0;
	return (tmp);
}
