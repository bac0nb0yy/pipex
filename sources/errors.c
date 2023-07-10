/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:15:00 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 08:15:00 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	assign_errors(t_data *data, char *error_message,
							char *error_path, int ret)
{
	data->error_message = error_message;
	data->error_path = error_path;
	data->ret_error = ret;
}

void	execute_errors(t_data *data, int ret_value, bool invalid)
{
	if (ret_value == RET_COMMAND_NOT_FOUND)
	{
		if (!invalid)
		{
			if (!data->command[0])
				assign_errors(data, COMMAND_NOT_FOUND, "", ret_value);
			else
				assign_errors(data, COMMAND_NOT_FOUND,
					data->command[0], ret_value);
		}
		else
			assign_errors(data, strerror(errno),
				data->cmd_path, ret_value);
	}
	else
		assign_errors(data, strerror(errno), data->cmd_path, ret_value);
	ft_dprintf(STDERR_FILENO, "pipex: %s: %s\n",
		data->error_path, data->error_message);
	free_struct(data, true, true);
	exit(data->ret_error);
}

void	error_file(t_data *data, char *filename)
{
	ft_dprintf(STDERR_FILENO, "pipex: %s: %s\n", filename, strerror(errno));
	free_struct(data, true, true);
	exit(EXIT_FAILURE);
}
