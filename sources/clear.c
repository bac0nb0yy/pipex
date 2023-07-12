/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:12:35 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/09 16:12:35 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipes(t_data *data, bool fd1, bool fd2)
{
	if (fd1 && data->pipe[0] != -1)
		close(data->pipe[0]);
	if (fd2 && data->pipe[1] != -1)
		close(data->pipe[1]);
}

void	free_struct(t_data *data, bool fd1, bool fd2, bool exec)
{
	ft_free_2d_array((void ***)&data->command);
	if (!exec)
		ft_free_2d_array((void ***)&data->paths);
	free(data->cmd_path);
	if (data->prev_pipe != -1)
		close(data->prev_pipe);
	close_pipes(data, fd1, fd2);
	clear_valid_fd(data);
}

void	clear_valid_fd(t_data *data)
{
	const int	fds[] = {data->fd1, data->fd2};
	size_t		i;

	i = 0;
	while (i < sizeof(fds) / sizeof(fds[0]))
	{
		if (fds[i] != -1)
			close(fds[i]);
		i++;
	}
}
