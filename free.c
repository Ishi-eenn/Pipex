/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:14:43 by tsishika          #+#    #+#             */
/*   Updated: 2023/07/21 14:38:52 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_two_d_array(char **two_d_array)
{
	int	i;

	i = 0;
	while (two_d_array[i] != NULL)
	{
		free(two_d_array[i]);
		i++;
	}
	free(two_d_array);
}
