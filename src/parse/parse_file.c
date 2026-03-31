#include "libft.h"
#include "matrix.h"
#include <fcntl.h>

/*
Faz a segunda passagem pelo arquivo, preenchendo a matriz
abre o arquivo novamente, lê linha por linha e para cada linha chama o parse_line
que recebe a matriz, a linha e o y atual, caso o parse_line falhe fecha o arquivo e retorna 0
se tudo ocorrer bem retorna 1 com a matriz completamente preenchida
*/
static  int fill_matrix(const char *filename, t_matrix *matrix)
{
    int fd;
    char *line;
    int y;

    y = 0;
    fd = open(filename, O_RDONLY);

    if (fd < 0)
        return (0);
    while((line = get_next_line(fd)) != NULL)
    {
        if(!parse_line(matrix, line, y))
        {
            free(line);
            close(fd);
            return (0);
        }
        free(line);
        y++;
    }
    close(fd);
    return (1);
}

/*
Função principal do parse_file, orquestra as funções auxiliares para o preenchimento da matriz
*/
t_matrix *parse_file(const char *filename)
{
    int height;
    int width;
    t_matrix *matrix;

    height = 0;
    width = 0;
    if(!valid_extension(filename))
        return (NULL);
    if(!get_map_size(filename, &width, &height))
        return (NULL);
    matrix = matrix_create(height, width);
    if (!matrix)
        return (NULL);
    if(!fill_matrix(filename, matrix))
    {
        matrix_destroy(matrix);
        return (NULL);
    }
    return (matrix);
}
