/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 00:36:27 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 00:36:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
char *ft_strjoin(char const *s1, char const *s2)
{
    size_t s1_len = ft_strlen(s1);
    size_t s2_len = ft_strlen(s2);
    int i;
    int j;
    char *copy;

    copy = malloc((s1_len + s2_len) + 1);
    if(!copy)
        return (NULL);
    i = 0;
    while(s1[i])
    {
        copy[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j])
    {
        copy[i + j] = s2[j];
        j++; 
    }
    copy[i + j] = '\0';
    return (copy);
}