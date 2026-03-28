/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:12:14 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 01:12:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    
    if(!s1 || !set)
        return (NULL);
    start = 0;
    while(s1[start] && ft_strchr(set, s1[start]))
        start++;
    end = ft_strlen(s1);
    while(end > start && ft_strchr(set, s1[end - 1]))
        end--;
    return (ft_substr(s1,start, end - start));
}