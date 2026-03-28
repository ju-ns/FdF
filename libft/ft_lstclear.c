/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 19:24:38 by marvin            #+#    #+#             */
/*   Updated: 2025/08/06 19:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_node;

	next_node = *lst;
	if(!lst || !del)
		return ;
	while(*lst)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
}
//outra versão reaproveitando a função lstdelone
// void	ft_lstclear(t_list **lst, void(*del)(void *))
// {
// 	t_list *temp;

// 	if(!lst || !del)
// 		return ;
// 	while(*lst)
// 	{
// 		temp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = temp;
// 	}
// }