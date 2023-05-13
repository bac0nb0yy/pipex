/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:31:12 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:28:33 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!tmp)
		return (NULL);
	while (s[i])
	{
		tmp[i] = s[i];
		++i;
	}
	tmp[i] = 0;
	return (tmp);
}
