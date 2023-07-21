/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:19:50 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/17 14:48:23 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1) + 1;
	dest = malloc(sizeof(char) * size);
	if (dest == NULL)
		return (0);
	ft_strlcpy(dest, s1, size);
	return (dest);
}
