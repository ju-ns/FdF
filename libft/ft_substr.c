/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:54:28 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 23:54:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t s_len;
    size_t i;

    if(!s)
        return (NULL);
    s_len = ft_strlen(s);
    if(start >= s_len)
        return(ft_strdup(""));
    if(len > s_len - start)
        len = s_len - start;
    sub = malloc(len + 1);
    if(!sub)
        return(NULL);
    i = 0;
    while(i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
