#include "matrix.h"
#include "fdf.h"
#include "render.h"

static void connect_points(t_fdf *fdf, s_point *point, int x, int y)
{
    if(x < fdf->matrix->width - 1)
        draw_line(fdf, *point, *matrix_get(fdf->matrix, x + 1, y));
    if(y < fdf->matrix->height - 1)
        draw_line(fdf, *point, *matrix_get(fdf->matrix, x, y + 1));
}

/*
Percorre todos os pontos da matriz e para cada ponto desenha até duas
linhas para a direita - conecta o ponto atual com o ponto à sua direita quando estivermos
na ultima coluna, linha para baixo - conecta o ponto atual com o ponto abaixo (x, y + 1).
A verificação y <height - 1 evita tentar pegar um ponto abaixo quando você já está na ultima linnha
o resultado é que cada ponto fica conectado ao da direta e ao de baixo formando uma grade
*/
void draw_map(t_fdf *fdf)
{
    int x;
    int y;
    s_point *p;

    y = 0;
    while(y < fdf->matrix->height)
    {
        x = 0;
        while(x < fdf->matrix->width)
        {
            p = matrix_get(fdf->matrix, x, y);
            connect_points(fdf, p, x, y);
            x++;
        }
        y++;
    }
}
