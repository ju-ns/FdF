#ifndef FDF_H
#define FDF_H

#define DEFAULT_COLOR 0xFFFFFF

/*
Responsável por guardar as cordenadas do 
input
*/
typedef struct point
{
    int x;
    int y;
    int z;
    int color;
    int screen_y;
    int screen_x;
} s_point;


typedef struct fdf 
{
    void *data_screen;
    void *win;
    void *img;
    char *addr;
    
    int bits_per_pixel;
    int line_length;
    int endian;

    t_matrix *matrix;
    
    int width;
    int height;

    int offset_x;
    int offset_y;
    int tile_size;
    int z_scale;
} t_fdf;

t_fdf *init_fdf(char *filename);



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


/*
utils do render
*/
int ft_abs(int n);
void init_line(t_line *line, s_point *a, s_point *b);
int total_steps(t_line *line);
void destroy_fdf(t_fdf *fdf);


/*
aplicação do algoritmo de breshman
*/
void    draw_line(t_fdf *fdf, s_point a, s_point b);


/*
tratamento de cor
*/
int interpolate_color(int color1, int color2, float t);

/*
Apoio para o hook
*/
int close_window(t_fdf *fdf);
int key_handler(int keycode, t_fdf *fdf);















#endif