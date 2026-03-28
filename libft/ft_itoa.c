/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:27:59 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 21:27:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int count_digits(int n)
{
    int len;

    len = (n <= 0);
    while(n != 0)
    {
       n /= 10;
       len++;
    }
    return (len);

}
static int handle_zero_case(char *result, int n)
{
    long nb;

    nb = n;
    if(nb == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return(1);
    }   
    return(0);
}

char *ft_itoa(int n)
{
    char *result;
    int len;
    long nb;

    nb = n;
    len = count_digits(n);
    result = malloc(len + 1);
    if(!result)
        return (NULL);
    result[len] = '\0';
    if(handle_zero_case(result,n))
        return (result);
    if(nb < 0)
    {
        result[0] = '-';
        nb = -nb;
    }    
    while(nb > 0)
    {
        result[--len] = (nb % 10) + '0';
        nb /= 10;
    }
    return (result);    
}
