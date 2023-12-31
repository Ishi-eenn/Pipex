/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:05 by tsishika          #+#    #+#             */
/*   Updated: 2023/09/06 22:19:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	exec(int pipefd[2], char **argv, char **environ)
{
	int		first_pid;
	int		second_pid;
	int		status;

	first_pid = front_exec(pipefd, argv, environ);
	judge_error(first_pid);
	second_pid = back_exec(pipefd, argv, environ);
	judge_error(second_pid);
	judge_error(close(pipefd[0]));
	judge_error(close(pipefd[1]));
	judge_error(waitpid(first_pid, &status, 0));
	judge_error(waitpid(second_pid, &status, 0));
	exit(WEXITSTATUS(status));
}

int	front_exec(int pipefd[2], char **argv, char **environ)
{
	pid_t	pid;
	int		file_fd;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		judge_error(close(pipefd[0]));
		is_read(argv[1]);
		file_fd = open_file(argv[1]);
		// file_fd = 0;
		judge_error(file_fd);
		judge_error(dup2(file_fd, 0));
		judge_error(dup2(pipefd[1], 1));
		handle_command(argv[2], environ);
	}
	return (pid);
}

int	back_exec(int pipefd[2], char **argv, char **environ)
{
	pid_t	pid;
	int		file_fd;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}
	if (pid == 0)
	{
		judge_error(close(pipefd[1]));
		if (!(is_write(argv[4])))
			exit_free_strerror("permission denied", argv[4], NULL, NULL);
		file_fd = open_or_create_file(argv[4]);
		// file_fd = 0;
		judge_error(file_fd);
		judge_error(dup2(pipefd[0], 0));
		judge_error(dup2(file_fd, 1));
		handle_command(argv[3], environ);
	}
	return (pid);
}
