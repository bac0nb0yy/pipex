/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:37:25 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:22:52 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	const size_t	bytes = nmemb * size;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(bytes);
	if (ptr != NULL && nmemb != 0 && size != 0)
		ft_bzero(ptr, bytes);
	return (ptr);
}
