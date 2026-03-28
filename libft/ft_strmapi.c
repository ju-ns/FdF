/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:19:31 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 18:19:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strmapi(char const *s, char(*f)(unsigned int, char))
{
    size_t s_len;
    unsigned int i;
    char *new_string;

    if(!s || !f)
        return (NULL);
    s_len = ft_strlen(s);
    new_string = malloc(s_len + 1);
    i = 0;
    while(s[i])
    {
        new_string[i] = f(i,s[i]);
        i++;
    }
    new_string[i] = '\0';
    return(new_string);
}
