/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:06:43 by marvin            #+#    #+#             */
/*   Updated: 2025/07/30 19:06:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n){
    const char *s;
    size_t i;
    char *d;

    s = (const char *) src;
    d = (char *) dst;
    i = 0;
    while(i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}