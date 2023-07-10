/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:08:49 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 16:47:58 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipes(t_data *data)
{
	if (data->cmd_id == 0)
	{
		data->fd1 = open(data->input_file, O_RDONLY);
		if (data->fd1 == -1)
			return (error_file(data, data->input_file));
		dup2(data->fd1, STDIN_FILENO);
	}
	else
		dup2(data->prev_pipe, STDIN_FILENO);
	if (data->cmd_id == data->nb_cmds - 1)
	{
		data->fd2 = open(data->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (data->fd2 == -1)
			return (error_file(data, data->output_file));
		dup2(data->fd2, STDOUT_FILENO);
	}
	else
		dup2(data->pipe[1], STDOUT_FILENO);
	if (data->prev_pipe != -1)
	{
		if (!ft_close(data->prev_pipe))
			exit(EXIT_FAILURE);
	}
	if (!free_struct(data, true, true))
		exit(EXIT_FAILURE);
}

static void	exec(t_data *data)
{
	int		ret_value;
	bool	invalid;

	invalid = false;
	ret_value = -1;
	if (!get_cmd_path(data))
		return (free_struct(data, true, true),
			perror("malloc"), exit(EXIT_FAILURE));
	if (data->cmd_path == NULL)
	ret_value = RET_COMMAND_NOT_FOUND;
	else if (access(data->cmd_path, F_OK) != 0)
	{
		if (errno == ENOTDIR || errno == EISDIR)
			ret_value = RET_CANNOT_EXECUTE;
		else
			ret_value = RET_COMMAND_NOT_FOUND;
		invalid = true;
	}
	else
	{
		ft_free_2d_array(data->paths);
		execve(data->cmd_path, data->command, data->env);
		ret_value = RET_CANNOT_EXECUTE;
	}
	execute_errors(data, ret_value, invalid);
}

static bool	wait_commands(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmds)
	{
		data->waitpid = wait(&data->ret_value);
		if (data->waitpid == -1)
			return (perror("wait"), false);
		if (data->waitpid == data->pid)
		{
			if (WIFEXITED(data->ret_value))
				data->ret_value = WEXITSTATUS(data->ret_value);
			else
				data->ret_value = 128 + WTERMSIG(data->ret_value);
			break ;
		}
		i++;
	}
	return (true);
}

static bool	pipex(t_data *data)
{
	while (data->cmd_id < data->nb_cmds)
	{
		pipe(data->pipe);
		data->pid = fork();
		if (data->pid == 0)
		{
			pipes(data);
			if (!parse_path(data, data->env) || !init_cmds(data))
				(free_struct(data, false, false),
					perror("malloc"), exit(EXIT_FAILURE));
			exec(data);
		}
		else
		{
			if (data->prev_pipe != -1 && !ft_close(data->prev_pipe))
				return (free_struct(data, true, true), false);
			data->prev_pipe = data->pipe[0];
			if (data->pipe[1] != -1 && !ft_close(data->pipe[1]))
				return (free_struct(data, true, false), false);
		}
		++data->cmd_id;
	}
	if (!free_struct(data, true, false) || !wait_commands(data))
		return (false);
	return (true);
}

int	main(int ac, char **av, char **env)
{
	t_data		data;

	if (!init_data(&data, ac, av, env))
		return (EXIT_FAILURE);
	if (!pipex(&data))
		return (EXIT_FAILURE);
	free_struct(&data, false, false);
	return (data.ret_value);
}
