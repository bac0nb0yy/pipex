/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcomp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 05:52:05 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/09 02:24:50 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strcomp(char *s1, char *s2)
{
	const int	s1_len = ft_strlen(s1);
	const int	s2_len = ft_strlen(s2);

	return (s1_len == s2_len && ft_strncmp(s1, s2, s1_len) == 0);
}
