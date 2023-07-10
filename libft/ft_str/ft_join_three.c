/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:39:00 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 06:39:00 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_three(char const *s1, char const *s2, char const *s3)
{
	char			*ret;
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	const size_t	len_s3 = ft_strlen(s3);

	ret = malloc(len_s1 + len_s2 + len_s3 + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, len_s1 + 1);
	ft_strlcpy(ret + len_s1, s2, len_s2 + 1);
	ft_strlcpy(ret + len_s1 + len_s2, s3, len_s3 + 1);
	return (ret);
}
