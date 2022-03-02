/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-berr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:21:52 by ple-berr          #+#    #+#             */
/*   Updated: 2022/01/14 15:13:30 by ple-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipex.h"

char	*ft_find(char **env, char *str)
{
	int	i;
	int	j;

	i = 0;
while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			while (env[i][j] == str[j])
				j++;
			if (str[j] == '\0')
				return (env[i]);
			else
				break ;
		}
		i++;
	}
	return (NULL);
}

void	ft_execve(char **env, char *typed_command, int n)
{
	char	*envp_path;
	char	*command;
	char	**command_args;
	char	**new_path;
	int		i;

	envp_path = ft_substr(ft_find(env, "PATH="), 0, 68);
	new_path = ft_split(envp_path, ':');
	command_args = ft_split(typed_command, ' ');
	i = -1;
	while ((new_path[++i]))
	{
		command = ft_strjoin(new_path[i], command_args[0], n);
		execve(command, command_args, env);
		free(command);
	}
	ft_errors(1, command_args[0]);
	exit(-1);
}

void	process_one(int file1, char *argv[], char **env)
{
	int	fd_in;
	int	n;

	n = 0;
	if (check_files(argv[1]) == -1)
		exit(1);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
	{
		ft_errors(0, argv[1]);
		exit(1);
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	dup2(file1, STDOUT_FILENO);
	close(file1);
	if (argv[2] == NULL)
	{
		ft_errors(2, NULL);
		exit(1);
	}
	ft_execve(env, argv[2], n);
}

void	process_two(int file2, char *argv[], char **env)
{
	int	fd_out;
	int	n;

	n = 0;
	if (check_files(argv[4]) == -1)
		exit(1);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out == -1)
		ft_errors(0, argv[4]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	dup2(file2, STDIN_FILENO);
	close(file2);
	if (argv[3] == NULL)
	{
		ft_errors(2, NULL);
		exit(1);
	}
	ft_execve(env, argv[3], n);
}

int	pipex(char *argv[], char **env)
{
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;

	pipe(fd_pipe);
	if (pipe(fd_pipe) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (1);
	if (pid1 == 0)
		process_one(fd_pipe[1], argv, env);
	close(fd_pipe[1]);
	waitpid(pid1, NULL, 0);
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)
		process_two(fd_pipe[0], argv, env);
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	waitpid(pid2, NULL, 0);
	return (0);
}
