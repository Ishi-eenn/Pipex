/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:19 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/20 18:49:10 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff_s;
	unsigned char	buff_c;

	i = 0;
	buff_s = (unsigned char *)s;
	buff_c = (unsigned char)c;
	while (i < n)
	{
		if (buff_s[i] == buff_c)
			return ((void *)&buff_s[i]);
		i++;
	}
	return (NULL);
}
