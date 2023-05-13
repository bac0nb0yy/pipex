/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 01:56:44 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/29 05:40:23 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	result;
	size_t	i;
	size_t	word;

	i = 0;
	result = 0;
	while (s[i])
	{
		word = 0;
		while (s[i] && s[i] != c)
		{
			word++;
			i++;
		}
		if (word)
			result = result + 1;
		if (word == ft_strlen(s) || i >= ft_strlen(s) - 1)
			break ;
		i++;
	}
	return (result);
}

static	size_t	get_size_word(size_t index, char const *s, char c)
{
	size_t	result;

	result = 0;
	while (s[index] && s[index] != c)
	{
		result++;
		index++;
	}
	return (result);
}

static	void	fill_word(size_t start, size_t end, char const *s, char *tmp)
{
	size_t	i;

	i = 0;
	while (start < end)
		tmp[i++] = s[start++];
	tmp[i] = 0;
}

static	int	*free_all(char **tmp, int index)
{
	while (index >= 0)
	{
		free(tmp[index]);
		--index;
	}
	free(tmp);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tmp;
	size_t	p;
	int		index;

	if (!s)
		return (NULL);
	tmp = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!tmp)
		return (NULL);
	p = 0;
	index = 0;
	while (p < ft_strlen(s))
	{
		if (get_size_word(p, s, c) >= 1)
		{
			tmp[index] = malloc(get_size_word(p, s, c) + 1);
			if (!tmp[index])
				free_all(tmp, index);
			fill_word(p, p + get_size_word(p, s, c), s, tmp[index]);
			index++;
		}
		p = p + get_size_word(p, s, c) + 1;
	}
	tmp[count_words(s, c)] = NULL;
	return (tmp);
}
