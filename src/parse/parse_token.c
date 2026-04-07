/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnogueir <jnogueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:06:37 by jnogueir          #+#    #+#             */
/*   Updated: 2026/03/31 16:08:56 by jnogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "parse.h"


/*
Responsável por preencher os dados de entrada na matriz, pega o 
ponteiro da estrutura s_point na posição (x, y) da matriz usando o
matriz get, guarda x e y como cordenadas de posição do mapa. Valida o
token com is_valid_token, extrai o valor z com parse_z e extrai a cor com
parse_color no final verifica x == matrix->width para garantir que o numero
de tokens bateu exatamente com a largura esperada da matriz
*/
static	int	fill_points(t_matrix *matrix, char **tokens, int y)
{
	int		x;
	s_point	*p;

	x = 0;
	while (tokens[x])
	{
		if (x >= matrix->width)
			return (0);
		p = matrix_get(matrix, x, y);
		if (!p)
			return (0);
		p->x = x;
		p->y = y;
		if (!is_valid_token(tokens[x]))
			return (0);
		p->z = parse_z(tokens[x]);
		p->color = parse_color(tokens[x]);
		x++;
	}
	return (x == matrix->width);
}

/*
Ponto de entrada, recebe uma linha inteira do arquivo como string
e o indice y da matriz, usa a split para quebrar essa string em tokens 
separados por espaço, cada token é um ponto da linha.
Passa os tokens para a função fill_points para fazer o trabalho real, se algo
falhar libera a memória e retorna 0
*/
int	parse_line(t_matrix *matrix, char *line, int y)
{
	char	**tokens;
	char	*trimmed;

	trimmed = ft_strtrim(line, "\n");
	tokens = ft_split(trimmed, ' ');
	free(trimmed);
	if (!tokens)
		return (0);
	if (!fill_points(matrix, tokens, y))
	{
		free_split(tokens);
		return (0);
	}
	free_split(tokens);
	return (1);
}
