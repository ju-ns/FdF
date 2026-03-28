#ifndef FDF_H
#define FDF_H

typedef struct point
{
    int x;
    int y;
    int z;
} s_point;


/*
Parsing
*/
int get_map_size(const char *filename, int *width, int *height);
int parse_line(t_matrix *matrix, char *line, int y);
int count_cols(const char *str);
void	free_split(char **str);











#endif