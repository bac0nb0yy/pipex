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

bool	init_cmds(t_data *data)
{
	data->command = ft_split(data->av[2 + data->cmd_id
			+ data->is_heredoc], ' ');
	if (!data->command)
		return (false);
	return (true);
}

static bool	init_args(t_data *data, int ac, char **av, char **env)
{
	const bool	bonus = ft_endswith(av[0], "_bonus");

	data->is_heredoc = (bonus && ft_strcomp(av[1], "here_doc"));
	if (bonus)
	{
		if (data->is_heredoc && ac < 6)
			return (ft_dprintf_bool(STDERR_FILENO, USAGE_B_HEREDOC, false));
		if (ac < 5)
			return (ft_dprintf_bool(STDERR_FILENO, USAGE_B_NOHEREDOC, false));
		data->limiter = av[2];
		data->input_file = av[1];
		data->output_file = av[ac - 1];
	}
	else
	{
		if (ac < 5 || ac > 6)
			return (ft_dprintf_bool(STDERR_FILENO, USAGE_M, false));
		data->input_file = av[1];
		data->output_file = av[ac - 1];
	}
	data->nb_cmds = ac - 3 - data->is_heredoc;
	data->env = env;
	data->av = av;
	return (true);
}

static bool	init_data_values(t_data *data)
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
	return (true);
}

bool	init_data(t_data *data, int ac, char **av, char **env)
{
	if (!init_args(data, ac, av, env) || !init_data_values(data))
		return (false);
	return (true);
}
