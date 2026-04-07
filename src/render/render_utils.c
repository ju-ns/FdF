#include "render.h"
#include <stdlib.h>

int ft_abs(int n)
{
    if(n < 0)
        return (-n);
    return (n);
}
/*
calcula quantos eixos mover no eixo x 
e no eixo y

toda reta entre dois pontos A e B é descrita por
y = mx + b
onde m = delta y / delta x ou m = (y2 - y1) / (x2 - x1)

Assim: 
delta x = x2 - x1 
delta y = y2 - y1 

são exatmente
dx = ft_abs(b->x - a->x)
dy = ft_abs(b->y - a->y)

sx e sy determinam quanto para andar para a direita ou esquerda
subir ou desce

vindos do sinal de x2 - x1 e y2 - y1 
se x2 > x1 então andar para a direita
se x2 < x1 andar para a esquerda

por isso:

dx = determina o tamanho do movimento
sx = sua direção

uma reta pode ser escrita da seguinte maneira:

F(x, y) = dx*y - dy*x + constante

para calcular qual pixel está mais proximo da reta ideal utilizando
essa formula sem usar o float

para isso usamos erro incremental inteiro e esse erro começa com 
err = dx - dy -> inicial

assim err vira o eixo que queremos priorizar, no fim multiplicamos por 2 para
simplificação algebrica do teste, basicamente o algoritmo transforma float comparison em integer comparison

separando em etapas estão:
equação da reta + distancia entre pixels + discretização incremental inteira
*/
void init_line(t_line *line, s_point *a, s_point *b)
{
    line->dx = ft_abs(b->screen_x - a->screen_x); //salvamos o delta x
    line->dy = ft_abs(b->screen_y - a->screen_y); //salvamos o delta y

    if(a->screen_x < b->screen_x) //verificamos para qual direção "andar"
        line->sx = 1;
    else
        line->sx = -1;
    if(a->screen_y < b->screen_y) //verificamos de subimos ou descemos
        line->sy = 1;
    else
        line->sy = -1;

    line->err = line->dx - line->dy; //calculamos o "erro" -> para qual lado a reta entre dois pontos distintos está se aproximando
}

