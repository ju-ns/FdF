#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "fdf.h"

/*
centraliza as funções responsaveis pela implementação gráfica
*/

t_fdf *init_fdf(char *filename);
t_fdf    *init_screen(void);
int create_image(t_fdf *win_struct);
int get_image_addr(t_fdf *win_struct);
void *new_window(void *data_screen, int width, int height, char *title);
void    get_screen_size(t_fdf *fdf);





#endif