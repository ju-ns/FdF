#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Uso: %s <arquivo>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // get_next_line já inclui o \n
        free(line);
    }

    close(fd);
    return 0;
}
