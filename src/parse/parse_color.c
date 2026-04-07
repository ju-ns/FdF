/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:57:53 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/31 15:59:52 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "render.h"


/*
Recebe o token e retorna apenas o valor da cordenada z
*/
int	parse_z(char *token)
{
	char	**slipt_array;
	int		z;

	slipt_array = ft_split(token, ',');
	if (!slipt_array)
		return (0);
	z = ft_atoi(slipt_array[0]);
	free_split (slipt_array);
	return (z);
}

/*
Recebe o token e retorna a cor 
*/
int	parse_color(char *token)
{
	char	**arr_split;
	int		color;

	if (!ft_strchr(token, ','))
		return (DEFAULT_COLOR);
	arr_split = ft_split(token, ',');
	if (!arr_split[1])
		return (DEFAULT_COLOR);
	color = ft_atoi_base(arr_split[1] + 2, 16);
	free_split(arr_split);
	return (color);
}
