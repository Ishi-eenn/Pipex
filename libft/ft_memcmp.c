/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:22 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/22 11:36:36 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buff_s1;
	unsigned char	*buff_s2;

	buff_s1 = (unsigned char *)s1;
	buff_s2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (buff_s1[i] == buff_s2[i]))
		i++;
	if (i == n)
		return (0);
	return ((int)(buff_s1[i] - buff_s2[i]));
}
