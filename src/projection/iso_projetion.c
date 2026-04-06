#include "matrix.h"
#include "fdf.h"


void init_projection_params(t_fdf *fdf)
{
    fdf->tile_size = 20;
    fdf->z_scale = 5;

    fdf->offset_x = fdf->width / 2 - (fdf->matrix->width * fdf->tile_size) / 2;
    fdf->offset_y = fdf->height / 2 - (fdf->matrix->height * fdf->tile_size) / 2;
}

/*
A ideia geral aqui é, percorrer a matriz e 
calcular onde cada ponto (y, x, z) deve aparecer na tela
o cálculo aqui escolhido foi a projeção isometrica
*/

void    project(t_fdf *fdf)
{
    int y; //iterados para percorrer a matriz
    int x;
    s_point *point; //recebe o ponto correspondete do mapa

    y = 0;
    while(y < fdf->matrix->height)
    {
        x = 0;
        while(x < fdf->matrix->width)
        {
            point = matrix_get(fdf->matrix, x, y);
            point->screen_x = (x - y) * fdf->tile_size + fdf->offset_x; //calculo para receber o screen_x, projeção isometrica

            point->screen_y = (x + y) * fdf->tile_size / 2 - point->z * fdf->z_scale / 4 + fdf->offset_y; //calculo para receber o screen_y, projeção isometrica
            x++;
        }
        y++;
    }
}

/*
Raciocinio adotado:
aqui estamos calculando os vetores que vão compor o nosso mapa
como não estamos usando perspectiva para a administração 3d, então não temos
um ponto menor no mapa para destacar a profundidade, temos vetores "paralelos" que definem as noções de profundidade para o 
nosso mapa 3d, a partir disso precisamos de dois calculos com base nos dados que já possuimos a partir do parse
precisamos saber a noção horizontal e a vertical para onde o nosso mapa cresce verticalmente e horizontalmente
*/