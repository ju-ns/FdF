#include <fcntl.h>
#include "matrix.h"

/*
Faz a leitura do arquivo, e conta as linhas e quantos tokens a primeira linha possui
Preenche esses valores via ponteiros e retorna 1 se o mapa é válido e zero se algo deu errado
*/
int get_map_size(const char *filename, int *width, int *height)
{
    int fd;
    char *line;
    int cols;

    fd = open(filename, O_RDONLY);
    if(fd < 0)
        return (0);
    while((line = get_next_line(fd)) != NULL)
    {
        cols = count_cols(line);
        if(cols == 0)
        {
            free(line);
            close(fd);
            return (0);
        }
        if (*height == 0)
            width = cols;
        else if (cols != *width)
        {
            free(line);
            close(fd);
            return (0);
        }
        (*height)++;
        free(line);
    }

    close(fd);
    return (*width > 0 && *height > 0);    
}