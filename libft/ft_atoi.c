/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:46:00 by marvin            #+#    #+#             */
/*   Updated: 2025/08/03 19:46:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int result;

    i = 0;
    result = 0;
    sign = 1;
    while(nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
        i++;
    if(nptr[i] == '-' || nptr[i] == '+')
    {
        if(nptr[i] == '-')
            sign = -1;
        i++;
    }
    while(nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }   
    return (result * sign);
}