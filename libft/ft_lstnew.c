/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:13:16 by marvin            #+#    #+#             */
/*   Updated: 2025/08/06 14:13:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
    t_list *newNode;

    newNode = malloc(sizeof(t_list));
    if(!newNode)
        return (NULL);
    newNode->content = content;
    newNode->next = NULL;
    return(newNode);
}