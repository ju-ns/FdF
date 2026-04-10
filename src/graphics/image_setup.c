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

    fdf = init_screen();
    if(!fdf)
        return (NULL);
    fdf->matrix = parse_file(filename);
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
    init_projection_params(fdf);
    return (fdf);
}
