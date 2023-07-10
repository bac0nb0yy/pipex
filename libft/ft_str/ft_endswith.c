/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 02:22:52 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/09 02:22:52 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_endswith(char *str, char *end)
{
	const size_t	str_len = ft_strlen(str);
	const size_t	end_len = ft_strlen(end);

	return (str_len >= end_len && ft_strcomp(str + str_len - end_len, end));
}
