/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 17:58:33 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:31:17 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	if (little[0] == 0)
		return ((char *)(big));
	while (big[i] && i < len)
	{
		k = 0;
		if (big[i] == little[k])
		{
			while (big[i + k] == little[k])
			{
				++k;
				if (i + k > len)
					break ;
				if (little[k] == 0)
					return ((char *)(&big[i]));
			}
		}
		++i;
	}
	return (NULL);
}
