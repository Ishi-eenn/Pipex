/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:44:22 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/22 10:49:51 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp_list;

	if (lst == NULL || f == NULL)
		return (NULL);
	res = ft_lstnew(f(lst->content));
	if (res == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		tmp_list = ft_lstnew(f(lst->content));
		if (tmp_list == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp_list);
		lst = lst->next;
	}
	return (res);
}
