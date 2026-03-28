/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 17:51:34 by marvin            #+#    #+#             */
/*   Updated: 2025/08/02 17:51:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
    int i;

    i = 0;
    while(s[i])
    {
        if(s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
    if((char)c == '\0')
        return((char *)&s[i]);
    return (NULL);
}