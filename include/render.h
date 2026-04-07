#ifndef RENDER_H
#define RENDER_H

#define KEY_ESC 65307

#include "matrix.h"
#include "fdf.h"



typedef struct line
{
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
    int e2;

} t_line;

/*
Responsaveis por implemetar a logica no tratamento de cores
e transição entre elas
*/
int get_r(int color);
int get_g(int color);
int get_b(int color);
int create_rgb(int r, int g, int b);
int interpolate_color(int color1, int color2, float t);

/*
responsaveis por implementar as contas necessárias para calcular o algoritmo de breshman
e outros calculos necessários para renderizar o mapa
*/
void draw_map(t_fdf *fdf);
void    put_pixel(t_fdf *fdf, int x, int y, int color);
void    draw_line(t_fdf *fdf, s_point a, s_point b);
int ft_abs(int n);
void init_line(t_line *line, s_point *a, s_point *b);
void clear_image(t_fdf *fdf);
void    render(t_fdf *fdf);


#endif