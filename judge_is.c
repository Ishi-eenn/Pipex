/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   judge_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:16:04 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 14:38:54 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_exec(char *command)
{
	if (access(command, X_OK) == 0)
		return (1);
	return (0);
}

void	is_read(char *file)
{
	if (access(file, F_OK) == -1)
		exit_free_strerror("no such file or directory", file, NULL, NULL);
	if (access(file, R_OK) == -1)
		exit_free_strerror("permission denied", file, NULL, NULL);
}

int	is_write(char *file)
{
	if (access(file, F_OK) == 0)
		if (access(file, W_OK) == -1)
			return (0);
	return (1);
}
