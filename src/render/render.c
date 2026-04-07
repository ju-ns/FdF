#include "fdf.h"
#include "mlx.h"
#include "render.h"
#include "libft.h"
#include "project.h"


void clear_image(t_fdf *fdf)
{
    int total_bytes;
    total_bytes = fdf->line_length * fdf->height;
    ft_memset(fdf->addr, 0, total_bytes);
}

void    render(t_fdf *fdf)
{
    clear_image(fdf);
    project(fdf);
    draw_map(fdf);
    mlx_put_image_to_window(
        fdf->data_screen,
        fdf->win,
        fdf->img,
        0,
        0
    );
}