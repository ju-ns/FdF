#include "fdf.h"
#include "render.h"

/*
Responsabilidade -> desenhar um pixel na imagem
como uma imagem é armazenada na memoria:
imagem = bloco contínuo de bytes: addr -> [linha 0][linha 1][linha 2]
cada linha oucupa line_length bytes

técnica utilizada:
Row-major ordering 
o que acontece, recebemos uma matrix bidmensional como input, para calcularmos o 
endereço de um elemento na memória precisamos deixa-la linear, a decisão aqui foi adotar
row wise arrangement onde a as linhas contem a quantidade de elementos em cada coluna, finalizadas 
as colunas passamos para a proxima linha
podemos visualizar da seguinte forma:

uma matriz 3 X 3
y
 1 2 3 
 1 2 2
 3 4 5 x
y -> guarda as linhas 
x -> as colunas

ao todo 3 colunas 
nosso array linear fica:

 [linha 0, coluna 0, valor 1][linha 0, coluna 1, valor 2][linha 0, coluna 2, valor 3][linha 1, coluna 0, valor 1] ...
 [1][2][3][1] ...

Não necessariamente fazemos essa converção exatamente nessa função mas vale mencionar como fator importante no momento
de calcular o endereço oara adicionar o pixel na image

pergunta, queremos desenhar um pixel na posição x = 2, y = 1, onde esse pixel esta?
agora a formula utilizada:

posição = y * witdh + x

como as imagens guardam byes (geralmente 32 bits por pixel) -> 4 bytes por pixel
posição real fica = (y * width + x) * bytes_por_pixel

porém o tamanho da minha linha não é garantido simplesmente por line_length == width * bytes_por_pixel

então em vez de width * bytes_por_pixel usamos line_length -> que significa quantos bytes existem em uma linha inteira 
da imagem 

estamos convertendo cordenadas 2d -> endereço linear em memoria

*/

void    put_pixel(t_fdf *fdf, int x, int y, int color)
{
    char    *dst;
    if(x < 0 || x >= fdf->width)
        return ;
    if(y < 0 || y >= fdf->height)
        return ;
    dst = fdf->addr //calcular a posição do pixel na memoria 
        + (y * fdf->line_length
        + x * (fdf->bits_per_pixel / 8));

    *(unsigned int *)dst = color; //recebe a cor no endereço estabelecido
}

/*
desenha varios pixels formando uma linha entre um ponto A -> B
nesse caso a função adota o algoritmo de bresennham, ele decide
andar no x?
andar no y?
andar nos dois?
*/
void    draw_line(t_fdf *fdf, s_point a, s_point b)
{
    t_line line;

    init_line(&line, &a, &b);
    while(1)
    {
        put_pixel(fdf, a.screen_x, a.screen_y, a.color);
        if(a.screen_x == b.screen_x && a.screen_y == b.screen_y)
            break;
        line.e2 = 2 * line.err;
        if(line.e2 > -line.dy)
        {
            line.err -= line.dy;
            a.screen_x += line.sx;
        }
        if(line.e2 < line.dx)
        {
            line.err += line.dx;
            a.screen_y += line.sy;
        }
    }
}
