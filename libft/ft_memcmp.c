/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 01:36:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/01 01:36:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned const char *ptr1;
    unsigned const char *ptr2;
    size_t i;

    ptr1 = (unsigned const char *) s1;
    ptr2 = (unsigned const char *) s2;

    i = 0;
    while(i < n)
    {
        if(ptr1[i] != ptr2[i])
            return(ptr1[i] - ptr2[i]);
        i++;
    }
    return (0);

}