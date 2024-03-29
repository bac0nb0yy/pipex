/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 09:04:23 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/16 21:29:04 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	end_heredoc(char *line, char *eof)
{
	const size_t	length = ft_strlen(eof);

	return (ft_strncmp(line, eof, length) == 0 && (line[length] == '\n'));
}

void	free_heredoc(t_heredoc *heredoc)
{
	t_heredoc_line	*current;
	t_heredoc_line	*tmp;

	current = heredoc->first;
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp->line);
		free(tmp);
	}
}

bool	push_back_heredoc(t_heredoc *heredoc, char *line)
{
	t_heredoc_line	*node;

	node = malloc(sizeof(t_heredoc_line));
	if (!node)
		return (false);
	node->line = line;
	node->next = NULL;
	if (heredoc->first == NULL)
	{
		heredoc->first = node;
		heredoc->last = node;
	}
	else
	{
		heredoc->last->next = node;
		heredoc->last = node;
	}
	return (true);
}

bool	read_heredoc(t_heredoc *heredoc, t_data *data)
{
	char	*line;

	heredoc->first = NULL;
	heredoc->last = NULL;
	while (true)
	{
		ft_dprintf(STDIN_FILENO, "> ");
		line = get_next_line(0);
		if (!line)
			return (get_next_line(GNL_FREE), perror("malloc"), false);
		if (end_heredoc(line, data->limiter))
			return (free(line), true);
		if (!push_back_heredoc(heredoc, line))
			return (get_next_line(GNL_FREE), ft_dprintf_bool(STDERR_FILENO,
					"Error: Heap full or malloc error\n", false));
	}
}

void	write_heredoc(t_heredoc *heredoc, t_data *data)
{
	t_heredoc_line	*current;
	long			line_len;
	int				write_fd;

	write_fd = data->pipe[1];
	current = heredoc->first;
	while (current)
	{
		line_len = ft_strlen(current->line);
		if (write(write_fd, current->line, line_len) != line_len)
			(perror("write"), free_heredoc(heredoc),
				close_pipes(data, true, true), exit(EXIT_FAILURE));
		current = current->next;
	}
}
