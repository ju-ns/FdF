#ifndef FDF_H
#define FDF_H

#define DEFAULT_COLOR 0xFFFFFF

typedef struct point
{
    int x;
    int y;
    int z;
    int color;
} s_point;


/*
Parsing
*/
int get_map_size(const char *filename, int *width, int *height);
int parse_line(t_matrix *matrix, char *line, int y);
int count_cols(const char *str);
void	free_split(char **str);
int cleanup(char *line, int fd, int exit_code);
int parse_z(char *token);
int parse_color(char *token);


/*
Validações para o parse,
estão no arquivo validations
*/
int is_valid_int(char *str);
int is_valid_color(char *str);
int valid_extension(const char *str);
















#endif