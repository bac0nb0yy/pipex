/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longest_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:51:31 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 05:51:39 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_longest_array(char *s1, char*s2)
{
	const int	len_a = ft_strlen(s1);
	const int	len_b = ft_strlen(s2);

	if (ft_max(len_a, len_b) == len_a)
		return (s1);
	return (s2);
}
