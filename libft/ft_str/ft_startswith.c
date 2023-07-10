/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 23:41:09 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/08 23:41:09 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_startswith(char *str, char *start)
{
	const size_t	str_len = ft_strlen(str);
	const size_t	start_len = ft_strlen(start);

	return (start_len <= str_len && ft_strncmp(str, start, start_len) == 0);
}
