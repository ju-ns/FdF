#include "fdf.h"
#include <stdlib.h>
#include "mlx.h"


t_fdf *init_fdf(char *filename)
{
    t_fdf *fdf;

    fdf = init_screen(1920, 1080);
    if(!fdf)
        return (NULL);
    fdf->width = 1920;
    fdf->height = 1080;

    fdf->matrix = parse_file(filename);
    if(!fdf->matrix)
    {
        destroy_fdf(fdf);
        return(NULL);
    }
        return (NULL);
    if(!create_image(fdf))
        return (NULL);
    if(!get_image_addr(fdf))
        return (NULL);
    init_projection_params(fdf);
    return (fdf);
}
