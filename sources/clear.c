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

static bool	close_pipes(t_data *data, bool fd1, bool fd2)
{
	if (fd1 && data->pipe[0] != -1)
	{
		if (!ft_close(data->pipe[0]))
			return (false);
	}
	if (fd2 && data->pipe[1] != -1)
	{
		if (!ft_close(data->pipe[1]))
			return (false);
	}
	return (true);
}

bool	free_struct(t_data *data, bool fd1, bool fd2)
{
	ft_free_2d_array(data->command);
	ft_free_2d_array(data->paths);
	free(data->cmd_path);
	if (!close_pipes(data, fd1, fd2) || !clear_valid_fd(data))
		return (false);
	return (true);
}

bool	clear_valid_fd(t_data *data)
{
	const int	fds[] = {data->fd1, data->fd2};
	int			i;

	i = 0;
	while (i < 2)
	{
		if (fds[i] != -1)
		{
			if (!ft_close(fds[i]))
				return (false);
		}
		i++;
	}
	return (true);
}
