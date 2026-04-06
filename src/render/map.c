#include "matrix.h"
#include "fdf.h"
#include "mlx.h"

void draw_map(t_fdf *fdf)
{
    int x;
    int y;
    s_point *p;
    s_point *right;
    s_point *down;

    y = 0;
    while(y < fdf->matrix->height)
    {
        x = 0;
        while(x < fdf->matrix->width)
        {
            p = matrix_get(fdf->matrix, x, y);
            if(x < fdf->matrix->width - 1)
            {
                right = matrix_get(fdf->matrix, x + 1, y);
                draw_line(fdf, *p, *right);
            }
            if(y < fdf->matrix->height - 1)
            {
                down = matrix_get(fdf->matrix, x, y + 1);
                draw_line(fdf, *p, *down);
            }
            x++;
        }
        y++;
    }
}
