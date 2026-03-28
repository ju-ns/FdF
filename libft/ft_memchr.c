/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:48:35 by marvin            #+#    #+#             */
/*   Updated: 2025/07/31 23:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    const unsigned char *ptr;
    size_t i;
    unsigned char d;

    d = (unsigned char) c;
    ptr = (const unsigned char *) s;

    i = 0;
    while(i < n)
    {
        if(ptr[i] == d)
            return ((void *) &ptr[i]);
        i++;
    }
    return NULL;
}