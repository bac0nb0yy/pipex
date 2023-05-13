/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:51 by dtelnov           #+#    #+#             */
/*   Updated: 2022/11/08 13:28:51 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*first_line(char *save)
{
	size_t	i;
	size_t	nl;
	char	*line;

	if (!save || save[0] == 0)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	nl = i;
	if (ft_strchr(save, '\n') != NULL)
		nl = i + 1;
	line = malloc(nl + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (ft_strchr(save, '\n') != NULL)
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*next_line(char *save)
{
	size_t	i;
	char	*line;
	char	*tmp;

	if (!save)
		return (NULL);
	tmp = ft_strchr(save, '\n');
	if (!tmp)
	{
		free(save);
		return (NULL);
	}
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(ft_strlen(save) - i);
	if (!line)
		return (NULL);
	tmp++;
	i = 0;
	while (*tmp)
		line[i++] = *tmp++;
	line[i] = 0;
	free(save);
	return (line);
}

char	*add_buf_to_save(char *save, char *buffer)
{
	char	*tmp;

	tmp = save;
	save = ft_strjoin(save, buffer);
	free(tmp);
	return (save);
}

char	*read_line(char *save, char *buffer, int fd)
{
	int		rd;

	rd = 42;
	while (rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd] = 0;
		if (!save)
			save = ft_calloc(1, 1);
		save = add_buf_to_save(save, buffer);
		if (ft_strchr(save, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	save[fd] = read_line(save[fd], buffer, fd);
	if (!save[fd])
		return (NULL);
	line = first_line(save[fd]);
	save[fd] = next_line(save[fd]);
	return (line);
}
