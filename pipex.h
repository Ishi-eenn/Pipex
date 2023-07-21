/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:15 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 15:59:19 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft/libft.h"

int		front_exec(int pipefd[2], char **argv, char **environ);
int		back_exec(int pipefd[2], char **argv, char **environ);
int		is_exec(char *command);
int		is_write(char *file);
int		open_or_create_file(char *file);
int		open_file(char *file);
char	**get_environ_str(char *key, char **environ);
char	*resolve_path(char *command, char *path_env);
char	**split_command(char *unformatted_command);
void	free_two_d_array(char **two_d_array);
void	exit_free_perror(char **free_string_array, char *free_string);
void	is_read(char *file);
void	handle_command(char *raw_command, char **environ);
void	exit_free_strerror(char *message, char *cmd_or_file,
			char **free_array, char *free_string);
void	arg_error(int argc);
void	exec(int pipefd[2], char **argv, char **environ);
void	judge_error(int id);
#endif
