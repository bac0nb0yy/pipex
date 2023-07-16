/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 03:28:48 by dtelnov          #+#    #+#             */
/*   Updated: 2023/07/10 04:56:36 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	init_heredoc(t_data *data)
{
	bool		read_status;
	t_heredoc	heredoc;
	pid_t		child_pid;

	if (pipe(data->pipe) == -1)
		return (perror("pipe"), false);
	read_status = read_heredoc(&heredoc, data);
	if (!read_status)
		return (free_heredoc(&heredoc), close_pipes(data, true, true), false);
	child_pid = fork();
	if (child_pid == -1)
		return (free_heredoc(&heredoc), close_pipes(data, true, true), false);
	if (child_pid == 0)
	{
		(write_heredoc(&heredoc, data), free_heredoc(&heredoc));
		get_next_line(GNL_FREE);
		close_pipes(data, true, true);
		exit(EXIT_SUCCESS);
	}
	(get_next_line(GNL_FREE), free_heredoc(&heredoc));
	close(data->pipe[1]);
	data->prev_pipe = data->pipe[0];
	return (true);
}

bool	init_cmds(t_data *data)
{
	data->command = ft_split(data->av[2 + data->cmd_id
			+ data->is_heredoc], ' ');
	return (data->command != NULL);
}

static void	init_args(t_data *data, int ac, char **av, char **env)
{
	const bool	bonus = ft_endswith(av[0], "_bonus");

	data->is_heredoc = (bonus && ft_strcomp(av[1], "here_doc"));
	if (bonus)
	{
		if (data->is_heredoc && ac < 6)
			(ft_dprintf(STDERR_FILENO, USAGE_B_HEREDOC), exit(EXIT_FAILURE));
		if (ac < 5)
			(ft_dprintf(STDERR_FILENO, USAGE_B_NOHEREDOC), exit(EXIT_FAILURE));
		if (data->is_heredoc)
			data->limiter = av[2];
		if (!data->is_heredoc)
			data->input_file = av[1];
		data->output_file = av[ac - 1];
	}
	else
	{
		if (ac != 5)
			(ft_dprintf(STDERR_FILENO, USAGE_M), exit(EXIT_FAILURE));
		data->input_file = av[1];
		data->output_file = av[ac - 1];
	}
	data->nb_cmds = ac - 3 - data->is_heredoc;
	data->env = env;
	data->av = av;
}

static void	init_data_values(t_data *data)
{
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	data->fd1 = -1;
	data->fd2 = -1;
	data->prev_pipe = -1;
	data->cmd_id = 0;
	data->ret_value = 0;
	data->cmd_path = NULL;
	data->command = NULL;
	data->paths = NULL;
	data->error_message = NULL;
	data->error_path = NULL;
	data->exec = false;
}

bool	init_data(t_data *data, int ac, char **av, char **env)
{
	init_args(data, ac, av, env);
	init_data_values(data);
	return (!data->is_heredoc || init_heredoc(data));
}
