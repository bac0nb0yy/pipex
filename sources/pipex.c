/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 03:08:49 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/17 21:09:39 by dtelnov          ###   ########.fr       */
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

char	*join_three_args(const char *path, char *delimiter, char *cmd)
{
	char		*ret;
	const int	path_len = ft_strlen(path);
	const int	delimiter_len = ft_strlen(delimiter);
	const int	cmd_len = ft_strlen(cmd);

	if (!path)
		return (NULL);
	if (!cmd)
	{
		ret = malloc(path_len + delimiter_len + 1);
		ft_memmove(ret, path, path_len);
		ft_memmove(ret + path_len, delimiter, delimiter_len + 1);
		return (ret);
	}
	ret = malloc(path_len + delimiter_len + cmd_len + 1);
	ft_memmove(ret, path, path_len);
	ft_memmove(ret + path_len, delimiter, delimiter_len);
	ft_memmove(ret + path_len + delimiter_len, cmd, cmd_len + 1);
	return (ret);
}

void	fork_one(int fd1, int fds[], char **av, char **env)
{
	const char	**paths = (const char **) parse_path(env);
	const char	**args = (const char **) ft_split(av[2], ' ');
	char		*curr;
	int			i;

	dup2(fd1, 0);
	dup2(fds[1], 1);
	close(fds[0]);
	close(fd1);
	i = 0;
	while (paths[i])
	{
		curr = join_three_args(paths[i], "/", (char *)args[0]);
		execve(curr, (char *const *)args, env);
		free(curr);
		++i;
	}
}

void	fork_two(int fd2, int fds[], char **av, char **env)
{
	const char	**paths = (const char **) parse_path(env);
	const char	**args = (const char **) ft_split(av[3], ' ');
	char		*curr;
	int			i;

	dup2(fd2, 1);
	dup2(fds[0], 0);
	close(fds[1]);
	close(fd2);
	i = 0;
	while (paths[i])
	{
		curr = join_three_args(paths[i], "/", (char *)args[0]);
		execve(curr, (char *const *)args, env);
		free(curr);
		++i;
	}
}

void	pipex(int fd1, int fd2, char **av, char **env)
{
	int		fds[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(fds);
	child1 = fork();
	// if (child1 < 0)
		// TODO
	if (child1 == 0)
		fork_one(fd1, fds, av, env);
	child2 = fork();
	// if (child2 < 0)
		// 	TODO
	if (child2 == 0)
		fork_two(fd2, fds, av, env);
	close(fds[0]);
	close(fds[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	int			fd1;
	int			fd2;

	(void) ac;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[4], O_WRONLY);
	pipex(fd1, fd2, av, env);
	return (0);
}
