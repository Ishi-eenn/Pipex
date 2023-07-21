/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:00 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 14:38:46 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	arg_error(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments.", 2);
		exit(1);
	}
}

void	exit_free_perror(char **free_string_array, char *free_string)
{
	perror("Error");
	if (free_string_array != NULL)
		free_two_d_array(free_string_array);
	if (free_string != NULL)
		free(free_string);
	exit(1);
}

int	ft_strcmp(char *a, char *b)
{
	while (1)
	{
		if (*a == '\0' && *b == '\0')
			return (1);
		if (*a != *b)
			return (0);
		a++;
		b++;
	}
}

void	exit_free_strerror(char *message, char *cmd_or_file,
					char **free_array, char *free_string)
{
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(cmd_or_file, 2);
	ft_putchar_fd('\n', 2);
	if (free_array != NULL)
		free_two_d_array(free_array);
	if (free_string != NULL)
		free(free_string);
	exit(1);
}
