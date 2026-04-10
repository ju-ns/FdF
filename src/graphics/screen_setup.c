#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>
#include "graphics.h"
#include "libft.h"

//cria a janela 
//cria a imagem 
//coloca a imagem na janela

t_fdf    *init_screen(void)
{
    t_fdf  *win_struct;

    win_struct = ft_calloc(1, sizeof(t_fdf));
    
    if(!win_struct)
        return (NULL);
    
    win_struct->data_screen = mlx_init(); //inicializo
    if(!win_struct->data_screen)
    {
        free(win_struct);
        return NULL;
    }
    get_screen_size(win_struct);
    win_struct->win = new_window(win_struct->data_screen, win_struct->width, win_struct->height, "FDF");
    if(!win_struct->win)
    {
        mlx_destroy_display(win_struct->data_screen);
        free(win_struct->data_screen);
        free(win_struct);
        return (NULL);
    }
   return (win_struct);
}

int create_image(t_fdf *win_struct)
{
    win_struct->img = mlx_new_image(
        win_struct->data_screen,
        win_struct->width,
        win_struct->height
    );
    if(!win_struct->img)
        return (0);
    return(1);
}

int get_image_addr(t_fdf *win_struct)
{
    win_struct->addr = mlx_get_data_addr(
        win_struct->img, 
        &win_struct->bits_per_pixel,
        &win_struct->line_length,
        &win_struct->endian
    );
    if(!win_struct->addr)
        return (0);
    return (1);
}
/*
abstração do mlx_get_screen_size para um tamanho dinamico da imagem
*/
void    get_screen_size(t_fdf *fdf)
{
    mlx_get_screen_size(fdf->data_screen, &fdf->width, &fdf->height);
    fdf->width *= 0.9;
}

void *new_window(void *data_screen, int width, int height, char *title)
{
    return (mlx_new_window(data_screen, width, height, title));
}


