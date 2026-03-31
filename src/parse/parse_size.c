/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:02:59 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/31 16:06:29 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "matrix.h"

/*
Utilitária: conta quantos tokens existem numa linha
do arquivo, retorna o width da matriz
*/
int	count_cols(const char *str)
{
	int	is_space;
	int	i;
	int	count;

	i = 0;
	is_space = 1;
	count = 0;

	while (str[i])
	{
		if (str[i] == ' ')
			is_space = 1;
		if (str[i] != ' ' && is_space)
		{
			count++;
			is_space = 0;
		}
		i++;
	}
	return (count);
}


/*
Faz a leitura do arquivo, e conta as linhas 
e quantos tokens a primeira linha possui
Preenche esses valores via ponteiros
 e retorna 1 se o mapa é válido e zero se algo deu errado
*/
int	get_map_size(const char *filename, int *width, int *height)
{
	int		fd;
	char	*line;
	int		cols;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		cols = count_cols(line);
		if (cols == 0)
			return (cleanup(line, fd, 0));
		if (*height == 0)
			*width = cols;
		else if (cols != *width)
			return (cleanup(line, fd, 0));
		(*height)++;
		free(line);
	}

	close(fd);
	return (*width > 0 && *height > 0);
}
