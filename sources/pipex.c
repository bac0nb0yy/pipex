/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:08:49 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/13 06:43:29 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	ft_startwith(char *str, char *start)
{
	const int	start_len = ft_strlen(start);
	int			i;

	i = 0;
	while (i < start_len)
	{
		if (str[i] != start[i])
			return (false);
		++i;
	}
	return (true);
}

char	**parse_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_startwith(env[i], "PATH="))
			return (ft_split(env[i] + 5, ':'));
		++i;
	}
	return (NULL);
}

// void    pipex(int f1, int f2, char *cmd1, char *cmd 2)
// {
//     int   end[2];
//     int   status;
//     pid_t child1;
//     pid_t child2;    pipe(end);
//     child1 = fork();
//     if (child1 < 0)
//          return (perror("Fork: "));
//     if (child1 == 0)
//         child_one(f1, cmd1);
//     child2 = fork();
//     if (child2 < 0)
//          return (perror("Fork: "));
//     if (child2 == 0)
//         child_two(f2, cmd2);
//     close(end[0]);
//     close(end[1]);
//     waitpid(child1, &status, 0);
//     waitpid(child2, &status, 0);
// }

int	main(int ac, char **av, char **env)
{
	int			fds[2];
	int			fd;
	pid_t		pid1, pid2;
	const char	*file1 = av[1];
	const char	*cmd1 = av[2];
	const char	*cmd2 = av[3];
	const char	*file2 = av[4];
	const char	**paths = (const char **) parse_path(env);

	(void) ac;
	(void) paths;
	pipe(fds);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fds[0]);
		fd = open(file1, O_RDONLY);
		dup2(fd, 0);
		close(fd);
		dup2(fds[1], 1);
		close(fds[1]);
		char *cmd1_args[] = {(char *)cmd1, NULL};
		execve(cmd1, cmd1_args, env);
	}
	else
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			close(fds[1]);
			dup2(fds[0], 0);
			close(fds[0]);
			fd = open(file2, O_WRONLY);
			dup2(fd, 1);
			close(fd);
			char *cmd2_args[] = {(char *)cmd2, "-l", NULL};
			execve(cmd2, cmd2_args, env);
		}
		else
		{
			close(fds[0]);
			close(fds[1]);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
	return (0);
}

