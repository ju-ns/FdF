#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"
#include "graphics.h"
#include "parse.h"
#include "hooks.h"
#include "project.h"
#include <stdio.h>


t_fdf *init_fdf(char *filename)
{
    t_fdf *fdf;

    fdf = init_screen(1920, 1080);
    if(!fdf)
        return (NULL);
    fdf->width = 1920;
    fdf->height = 1080;

    fdf->matrix = parse_file(filename);
    printf("matrix: %p\n", fdf->matrix);
    if(!fdf->matrix)
    {
        printf("parse failed\n");
        destroy_fdf(fdf);
        return(NULL);
    }
    if(!create_image(fdf))
        return (NULL);
    if(!get_image_addr(fdf))
        return (NULL);
    printf("img: %p\n", fdf->img);
    printf("addr: %p\n", fdf->addr);
    init_projection_params(fdf);
    return (fdf);
}
