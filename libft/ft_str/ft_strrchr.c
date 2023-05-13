/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:50:11 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:31:30 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*tmp;

	tmp = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			tmp = (char *)(s + i);
		++i;
	}
	if (s[i] == (unsigned char)c)
		tmp = (char *)(s + i);
	if (tmp)
		return (tmp);
	return (NULL);
}
