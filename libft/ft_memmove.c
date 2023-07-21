/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:01:28 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/21 17:36:19 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*buff_dst;
	const unsigned char	*buff_src;

	i = 1;
	if (dst == NULL && src == NULL)
		return (NULL);
	buff_dst = (unsigned char *)dst;
	buff_src = (const unsigned char *)src;
	if (buff_dst < buff_src)
	{
		ft_memcpy(dst, src, len);
		return (dst);
	}
	while (i <= len)
	{
		buff_dst[len - i] = buff_src[len - i];
		i++;
	}
	return (dst);
}
