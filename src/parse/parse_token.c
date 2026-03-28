#include "matrix.h"
#include "libft.h"
#include "fdf.h"
/*
Utilitaria: libera a array depois de alocar 
a memória com split
*/
void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
/*
Utilitária: conta quantos tokens existem numa linha
do arquivo, retorna o width da matriz
*/
int count_cols(const char *str)
{
    int is_space;
    int i;
    int count;

    i = 0;
    is_space = 1;
    count = 0;

    while(str[i])
    {
        if(str[i] == ' ')
            is_space = 1;
        if(str[i] != ' ' && is_space)
        {
            count++;
            is_space = 0;
        }
        i++; 
    }
    return (count);
}
/*
Utilitária para prencher os dados
*/
static int fill_points(t_matrix *matrix, char **tokens, int y)
{
    int x;
    s_point *p;

    x = 0;
    while(tokens[x])
    {
        if (x >= matrix->width)
            return (0);
        p = matrix_get(matrix, x, y);
        if (!p)
            return (0);
        p->x = x;
        p->y = y;
        p->z = ft_atoi(tokens[x]);
        x++;
    }
    return (x == matrix->width);
}
/*
Preenche cada s_point da linha y com as três cordenadas x y z
*/
int parse_line(t_matrix *matrix, char *line, int y)
{
    char **tokens;

    tokens = ft_split(line, ' ');
    if(!tokens)
        return (0);
    if(!fill_points(matrix, tokens, y))
    {
        free_split(tokens);
        return (0);
    }
    free_split(tokens);
    return (1);
}
