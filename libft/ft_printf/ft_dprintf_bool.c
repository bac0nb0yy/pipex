/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_bool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:30:48 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 06:30:48 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_dprintf_bool(int fd, char *str, bool value)
{
	return (ft_dprintf(fd, str), value);
}
