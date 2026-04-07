#ifndef HOOKS_H
#define HOOKS_H

#include "fdf.h"

void destroy_fdf(t_fdf *fdf);
int close_window(t_fdf *fdf);
int key_handler(int keycode, t_fdf *fdf);

#endif