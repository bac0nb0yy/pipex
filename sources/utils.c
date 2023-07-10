/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 03:35:13 by dtelnov          #+#    #+#             */
/*   Updated: 2023/07/10 06:49:07 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ft_close(int fd)
{
	if (close(fd) == -1)
		return (false);
	return (true);
}

bool	get_cmd_path(t_data *data)
{
	int		i;
	char	*tmp;

	if (ft_strchr(data->command[0], '/'))
	{
		data->cmd_path = data->command[0];
		return (true);
	}
	i = 0;
	while (data->paths[i])
	{
		tmp = join_three(data->paths[i], "/", data->command[0]);
		if (!tmp)
			return (false);
		if (access(tmp, F_OK) == 0)
			return (data->cmd_path = tmp, true);
		free(tmp);
		i++;
	}
	return (true);
}

bool	parse_path(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_startswith(env[i], "PATH="))
		{
			data->paths = ft_split(env[i] + 5, ':');
			return (data->paths != NULL);
		}
		++i;
	}
	return (true);
}
