/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <syi378039@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:44:13 by tsishika          #+#    #+#             */
/*   Updated: 2023/05/21 23:30:37 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_list;
	t_list	*del_list;

	if (lst == NULL || del == NULL)
		return ;
	tmp_list = *lst;
	while (tmp_list != NULL)
	{
		del_list = tmp_list;
		tmp_list = tmp_list->next;
		ft_lstdelone(del_list, del);
	}
	*lst = NULL;
}
