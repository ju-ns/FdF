/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:10:52 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 13:10:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int   ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned const char *str1;
    unsigned const char *str2;
    size_t i;

    str1 = (unsigned const char *) s1;
    str2 = (unsigned const char *) s2;

    i = 0;
    while(i < n)
    {
        if(str1[i] != str2[i])
            return(str1[i] - str2[i]);
        if(str1[i] == '\0')
            break;
        i++;
    }
    return (0);

}