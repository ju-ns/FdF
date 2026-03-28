/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:13:08 by marvin            #+#    #+#             */
/*   Updated: 2025/08/06 14:13:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if(!lst || !new)
		return;
	if(*lst == NULL)
	{
		*lst = new;
		return;
	}
	last = *lst;
	while(last->next)
		last = last->next;
	last->next = new;

}