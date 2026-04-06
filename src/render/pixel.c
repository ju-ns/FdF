#include "mlx.h"
#include "fdf.h"
#include "render.h"
#include <stdlib.h>
#include <math.h>

void    put_pixel(t_fdf *fdf, int x, int y, int color)
{
    char    *dst;
    if(x < 0 || x >= fdf->width)
        return ;
    if(y < 0 || y >= fdf->height)
        return ;
    dst = fdf->addr
        + (y * fdf->line_length
        + x * (fdf->bits_per_pixel / 8));

    *(unsigned int *)dst = color;
}

void    draw_line(t_fdf *fdf, s_point a, s_point b)
{
    t_line *line;
    int total_steps;
    int step;

    init_line(line, a, b);
    total_steps = total_steps(line);
    step = 0;
    while(1)
    {
        put_pixel(fdf, a.screen_x, a.screen_y, a.color);
        if(a.screen_x == b.screen_x 
            && a.screen_y == b.screen_y)
            break;
        line.e2 = 2 * line.err;
        if(line.e2 > -line.dy)
        {
            line.err -= line.dy;
            a.screen_x += line.sx;
        }
        if(line.e2 < line.dx)
        {
            line.err += line.dx;
            a.screen_y += line.sy;
        }
        step ++;
    }
}
