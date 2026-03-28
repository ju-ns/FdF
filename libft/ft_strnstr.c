/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 14:45:45 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 14:45:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t i;
    size_t needle_len;

    needle_len = ft_strlen(needle);
    i = 0;
    if(*needle == '\0')
        return ((char *)haystack);
    while(haystack[i] && (i + needle_len) <= len)
    {
        if(ft_strncmp(&haystack[i], needle, needle_len) == 0)
            return((char *)&haystack[i]);
        i++;
    }
    return (NULL);
}