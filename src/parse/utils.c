#include "libft.h"

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
Utilitaria: responsável pela limpeza e fechamento do fd, retorna o exit_code determinado pelo user
*/
int cleanup(char *line, int fd, int exit_code)
{
    free(line);
    close(fd);
    return (exit_code);
}


