/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:53:56 by tsishika          #+#    #+#             */
/*   Updated: 2023/08/25 02:29:46 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

char	**get_environ_str(char *key, char **environ)
{
	int		i;
	char	**value;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], key, ft_strlen(key)) == 0)
		{
			value = ft_split(environ[i], '=');
			return (value);
		}
		i++;
	}
	return (NULL);
}

char	**split_command(char *unformatted_command)
{
	char	**command;

	command = ft_split(unformatted_command, ' ');
	return (command);
}

char	*resolve_path(char *command, char *path_env)
{
	char	**paths;
	char	*path;
	char	*full_path;
	int		i;

	paths = ft_split(path_env, ':');
	i = 0;
	while (paths[i] != NULL)
	{
		path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(path, command);
		free(path);
		if (is_exec(full_path))
		{
			free_two_d_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_two_d_array(paths);
	return (NULL);
}

void	handle_command(char *raw_command, char **environ)
{
	char	**command;
	char	*command_full_path;
	char	**path_env;

	command = split_command(raw_command);
	if (command == NULL)
		exit_free_perror(NULL, NULL);
	if (is_exec(command[0]))
	{
		execve(command[0], command, environ);
		exit_free_perror(command, NULL);
	}
	path_env = get_environ_str("PATH", environ);
	command_full_path = resolve_path(command[0], path_env[1]);
	free_two_d_array(path_env);
	if (command_full_path == NULL)
		exit_free_strerror("command not found", command[0], command, NULL);
	execve(command_full_path, command, environ);
	exit_free_perror(command, command_full_path);
}
