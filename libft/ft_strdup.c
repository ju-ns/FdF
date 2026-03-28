/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:23:50 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 20:23:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
char *ft_strdup(const char *s)
{
    size_t i;
    char *copy;

    i = 0;
    copy = malloc(ft_strlen(s) + 1);
    if(!copy)
        return (NULL);
    while(s[i])
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);    
}