#include "fdf.h"
#include "matrix.h"
#include "render.h"
#include "mlx.h"
#include <stdlib.h>

int ft_abs(int n)
{
    if(n < 0)
        return (-n);
    return (n);
}


void init_line(t_line *line, s_point *a, s_point *b)
{
    line->dx = ft_abs(b->screen_x - a->screen_x);
    line->dy = ft_abs(b->screen_y - a->screen_y);

    if(a->screen_x < b->screen_x)
        line->sx = 1;
    else
        line->sx = -1;
    if(a->screen_y < b->screen_y)
        line->sy = 1;
    else
        line->sy = -1;

    line->err = line->dx - line->dy;
}

int total_steps(t_line *line)
{
    if(line->dx > line->dy)
        return(line->dx);
    
     return(line->dy);
}

