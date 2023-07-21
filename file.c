/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:57:55 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 14:38:50 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	open_or_create_file(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC);
	if (fd == -1)
		return (-1);
	return (fd);
}
