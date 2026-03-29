#include "libft.h"
#include "fdf.h"


/*
Recebe o token e retorna apenas o valor da cordenada z
*/
int parse_z(char *token)
{
    char **slipt_array;
    int z;

    slipt_array = ft_split(token, ',');
    if (!slipt_array)
        return (0);
    z = ft_atoi(slipt_array[0]); //guarda apenas a cordenada z
    free_split(slipt_array);
    return (z);
}
/*
Recebe o token e retorna a cor 
*/
int parse_color(char *token)
{
    char **arr_split;
    int color;

    if(!ft_strchr(token, ','))
        return (DEFAULT_COLOR);
    arr_split = ft_split(token, ',');
    if(!arr_split[1])
        return (DEFAULT_COLOR);
    color = ft_atoi_base(arr_split[1] + 2, 16);
    free_split(arr_split);
    return color;    
}
