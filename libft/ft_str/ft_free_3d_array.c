/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_3d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 06:34:57 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 06:34:57 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_3d_array(char ***array)
{
	int	i;

	if (!array || !*array || !**array)
		return ;
	i = 0;
	while (array[i])
	{
		ft_free_2d_array(array[i]);
		i++;
	}
	free(array);
}
