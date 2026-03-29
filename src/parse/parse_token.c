#include "matrix.h"
#include "libft.h"
#include "fdf.h"


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
        p->z = parse_z(tokens[x]);
        p->color = parse_color(tokens[x]);
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
