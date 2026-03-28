/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:16:51 by marvin            #+#    #+#             */
/*   Updated: 2026/03/26 16:16:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Converte uma string para long verificando o overflow
retorna 0 caso a conversão tenha falhado, caso contrário 
realiza a conversão e retorna 1 para verdadeiro
*/
int	ft_atoi_safe(char *str, long *result)
{
	long	num;
	int		sign;
	int		i;

	if (!str || !result)
		return (0);
	sign = 1;
	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	*result = num;
	return (1);
}