/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:11:10 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/24 06:14:07 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*p;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	p = ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	p[len] = '\0';
	i = 0;
	while (i < len)
	{
		p[i] = f(i, s[i]);
		i++;
	}
	return (p);
}
