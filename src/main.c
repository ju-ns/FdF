#include "libft.h"
#include "fdf.h"
#include "render.h"
#include "mlx.h"

int main(int argc, char **argv)
{
    t_fdf *fdf;
    if(argc != 2)
        return (1);
    fdf = init_fdf(argv[1]);
    if(!fdf)
        return (1);
    render(fdf);

    mlx_key_hook(fdf->win, key_handler, fdf);
    mlx_hook(fdf->win, 17, 0, close_window, fdf);

    mlx_loop(fdf->data_screen);
    return (0);
}


