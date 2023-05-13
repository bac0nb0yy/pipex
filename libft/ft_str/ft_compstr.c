/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:52:05 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 05:52:06 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_compstr(char *s1, char *s2)
{
	char	*smallest_array;
	char	*longest_array;
	int		i;

	i = 0;
	longest_array = ft_longest_array(s1, s2);
	if (longest_array == s1)
		smallest_array = s2;
	else
		smallest_array = s1;
	while (longest_array[i])
	{
		if (longest_array[i] != smallest_array[i])
			return (false);
		++i;
	}
	return (true);
}
