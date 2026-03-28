/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 15:56:24 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 15:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t src_len;
    size_t dst_len;

    i = 0;
    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    
    if(size <= dst_len)
        return(src_len + size);
    while(src[i] && (dst_len + i < size - 1))
    {
        dst[dst_len + i] = src[i];
        i++;
    }
    dst[dst_len + i] = '\0';
    
    return (dst_len + src_len);     
}