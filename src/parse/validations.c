/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:10:43 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/31 16:14:26 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

/*
Utilitária para validar os valores da cordenada z
retorna zero para um valor inválido e um para válido
*/
int	is_valid_int(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
Utilitaria para validar os valores do hexadecimal que representa a cor
retorna zero para um valor inválido e um para válido
*/
int	is_valid_color(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '0' && str[i + 1] == 'x')
		i = 2;
	else
		return (0);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i])
			&& !(str[i] >= 'A' && str[i] <= 'F')
			&& !(str[i] >= 'a' && str[i] <= 'f'))
			return (0);
		i++;
	}
	return (1);
}

/*
Valida se a extensão do arquivo está correta,
caso não se trate de um arquivo .fdf retorna zero
*/
int	valid_extension(const char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 5)
		return (0);
	if (!ft_strncmp(str + len - 4, ".fdf", 4))
		return (1);
	return (0);
}

/*
Centraliza as validações executadas em
is_valid_color e is_valid_token
*/
int	is_valid_token(char *str)
{
	char	**arr;

	if (!str)
		return (0);
	arr = ft_split(str, ',');
	if (!is_valid_int(arr[0]))
		return (0);
	if (arr[1])
		if (!is_valid_color(arr[1]))
			return (0);
	free_split(arr);
	return (1);
}
