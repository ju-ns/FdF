#include "fdf.h"
#include "mlx.h"
#include "render.h"


void destroy_fdf(t_fdf *fdf)
{
    if(!fdf)
        return ;
    if(fdf->img)
        mlx_destroy_image(fdf->data_screen, fdf->img);
    if(fdf->win)
        mlx_destroy_window(fdf->data_screen, fdf->win);
    if(fdf->data_screen)
    {
        mlx_destroy_display(fdf->data_screen);
        free(fdf->data_screen);
    }
    if(fdf->matrix)
        matrix_destroy(fdf->matrix);
    free(fdf);
}

int close_window(t_fdf *fdf)
{
    destroy_fdf(fdf);
    exit(0);
}

int key_handler(int keycode, t_fdf *fdf)
{
    if(keycode == KEY_ESC)
        close_window(fdf);
    return (0);
}