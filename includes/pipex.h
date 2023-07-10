/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:31 by dtelnov           #+#    #+#             */
/*   Updated: 2023/07/10 16:59:01 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define USAGE_M	"usage: ./pipex file1 cmd1 cmd2 file2\n"
# define USAGE_B	"usage: ./pipex_bonus here_doc LIMITER cmd cmd1 file\n"

# define COMMAND_NOT_FOUND		"command not found"

# define RET_CANNOT_EXECUTE		126
# define RET_COMMAND_NOT_FOUND	127

typedef struct s_data
{
	char		**env;
	char		**av;
	char		**paths;
	char		**command;
	char		*cmd_path;
	char		*input_file;
	char		*output_file;
	char		*limiter;
	char		*error_message;
	char		*error_path;
	pid_t		pid;
	pid_t		waitpid;
	int			pipe[2];
	int			fd1;
	int			fd2;
	int			prev_pipe;
	int			nb_cmds;
	int			cmd_id;
	int			ret_value;
	int			ret_error;
	bool		is_heredoc;
}				t_data;

//utils.c
bool	parse_path(t_data *data, char **env);
bool	get_cmd_path(t_data *data);
bool	ft_close(int fd);

//init.c
bool	init_data(t_data *data, int ac, char **av, char **env);
bool	init_cmds(t_data *data);

//clear.c
bool	clear_valid_fd(t_data *data);
bool	free_struct(t_data *data, bool fd1, bool fd2);

//errors.c
void	error_file(t_data *data, char *filename);
void	execute_errors(t_data *data, int ret_value, bool invalid);
#endif