/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:54:11 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 14:38:59 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

int	main(int argc, char **argv)
{
	int			pipefd[2];
	extern char	**environ;

	arg_error(argc);
	if (pipe(pipefd) != -1)
	{
		perror("Error");
		exit(1);
	}
	exec(pipefd, argv, environ);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q pipex");
// }
