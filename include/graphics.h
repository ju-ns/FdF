#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "fdf.h"

/*
centraliza as funções responsaveis pela implementação gráfica
*/

t_fdf *init_fdf(char *filename);
t_fdf    *init_screen(int width, int height);
int create_image(t_fdf *win_struct);
int get_image_addr(t_fdf *win_struct);



#endif