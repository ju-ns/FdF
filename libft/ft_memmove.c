/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:44:13 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 20:44:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void *ft_memmove(void *dst, const void *src, size_t n)
{  
    unsigned char *copy; 
    const unsigned char *s; 
    size_t i; 

    copy = (unsigned char *) dst;
    s = (const unsigned char *) src;

    if(!dst && !src)
        return (NULL);

    if(copy > s)
    {
        i = n; 
        while(i >  0)
        {
            i--;
            copy[i] = s[i];
        }
    }
    else{
        ft_memcpy(dst, src, n);
    }
    return(dst);
}