/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:08:49 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/12 08:06:48 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	pipes(t_data *data)
{
	if (data->cmd_id == 0)
	{
		data->fd1 = open(data->input_file, O_RDONLY);
		if (data->fd1 == -1)
			error_file(data, data->input_file);
		dup2(data->fd1, STDIN_FILENO);
	}
	else
		dup2(data->prev_pipe, STDIN_FILENO);
	if (data->cmd_id == data->nb_cmds - 1)
	{
		data->fd2 = open(data->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->fd2 == -1)
			error_file(data, data->output_file);
		dup2(data->fd2, STDOUT_FILENO);
	}
	else
		dup2(data->pipe[1], STDOUT_FILENO);
	if (data->prev_pipe != -1)
		close(data->prev_pipe);
	free_struct(data, true, true, false);
}

static void	exec(t_data *data)
{
	int		ret_value;
	bool	invalid;

	invalid = false;
	data->exec = false;
	if (!get_cmd_path(data))
		exit_error_command(data, false, false, "malloc");
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
		ft_free_2d_array((void ***)&data->paths);
		data->exec = true;
		execve(data->cmd_path, data->command, data->env);
		ret_value = RET_CANNOT_EXECUTE;
	}
	execute_errors(data, ret_value, invalid, data->exec);
}

static int	wait_commands(t_data *data)
{
	while (1)
	{
		data->waitpid = wait(&data->waitstatus);
		if (data->waitpid == -1)
			break ;
		if (data->waitpid != data->pid || data->ret_value != EXIT_SUCCESS)
			continue ;
		if (WIFEXITED(data->waitstatus))
			data->ret_value = WEXITSTATUS(data->waitstatus);
		else
			data->ret_value = 128 + WTERMSIG(data->waitstatus);
	}
	return (data->ret_value);
}

static int	pipex(t_data *data)
{
	while (data->cmd_id < data->nb_cmds)
	{
		pipe(data->pipe);
		data->pid = fork();
		if (data->pid == -1)
			exit_error_command(data, true, true, "fork");
		if (data->pid == 0)
		{
			pipes(data);
			if (!parse_path(data, data->env) || !init_cmds(data))
				exit_error_command(data, false, false, "malloc");
			exec(data);
		}
		else
		{
			if (data->prev_pipe != -1)
				close(data->prev_pipe);
			data->prev_pipe = data->pipe[0];
			close(data->pipe[1]);
		}
		++data->cmd_id;
	}
	free_struct(data, true, false, false);
	return (wait_commands(data));
}

int	main(int ac, char **av, char **env)
{
	t_data		data;

	if (!init_data(&data, ac, av, env))
		return (EXIT_FAILURE);
	return (pipex(&data));
}
