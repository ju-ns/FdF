#include "matrix.h"

/*
Cria a estrutura e aloca memório para os s_points
o valor de retorno é t_matriz *
*/
t_matrix *matrix_create(int width, int height)
{
    t_matrix *matrix;

    matrix = malloc(sizeof(t_matrix)); //aloco a memoria para a estrutura
    if (!matrix)
        return (NULL);
    matrix->width = width; //salvar os valores das linhas e colunas 
    matrix->height = height;
    matrix->data = malloc(sizeof(s_point) * width * height); //alocar a memoria para as cordenadas
    if (!matrix->data)
    {
        free(matrix);
        return (NULL);
    }
    return (matrix);
}   

/*
Libera a memória alocada pela matriz
*/
void	matrix_destroy(t_matrix *matrix)
{
    if (!matrix)
        return ;
    free(matrix->data);
    free(matrix);
}
/*
Recebe um par de cordenadas e retorna um ponteiro 
para o s_point correspondente na matriz, 
retorna NULL se houver algo errado
*/
s_point *matrix_get(t_matrix *matrix, int x, int y)
{
    s_point *data;
    
    if(!matrix)
        return (NULL);
    if (x < 0 || y < 0)
        return (NULL);
    if (x >= matrix->width || y >= matrix->height)
        return (NULL);
    data = (s_point *)matrix->data;
    return (&data[y * matrix->width + x]);
}

/*
Altera os dados armazenados pelo s_point dentro da matriz
*/
void	matrix_set(t_matrix *matrix, int x, int y, s_point value)
{
    s_point *data;
    if(!matrix)
        return ;
    if (x < 0 || y < 0)
        return ;
    if (x >= matrix->width || y >= matrix->height)
        return ;
    data = matrix->data;
    data[y * matrix->width + x] = value;
}
