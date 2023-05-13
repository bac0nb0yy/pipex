/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:49:22 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:31:58 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	check(char const *set, char a)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (a == set[i])
			return (1);
		++i;
	}
	return (0);
}

static	size_t	start_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && check(set, s1[i]) == 1)
		++i;
	return (i);
}

static	size_t	end_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s1) && check(set, s1[ft_strlen(s1) - i - 1]) == 1)
		++i;
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = start_index(s1, set);
	end = end_index(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	tmp = malloc(end - start + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (start < end)
	{
		tmp[i] = s1[start];
		i++;
		start++;
	}
	tmp[i] = 0;
	return (tmp);
}
