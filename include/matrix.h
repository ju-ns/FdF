#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

/*
Responsável por guardar as cordenadas do 
input

Relação s_point X t_matrix

t_matrix = conteiner 
s_point = dado

A t_matriz guarda largura, a altura e o ponteiro data que aponta para 
um array de s_points alocado na memoria. Esse array tem width * height elementos
um para cada célula do mapa

Cada s_point representa um ponto do mapa e guarda tudo sobre ele: onde ele está no mapa
(x, y, z), a cor, e onde ele vai aparecer na tela depois da projeção (screen_x, screen_y).

posição horizontal p->x (coluna) | posição vertical p->y (linha) | p->z (valor)

Para acessar o ponto na coluna 2, linha 2, a fórmula do índice no array y * width + x 
ou seja, na posição 12 no array. É isso que matrix_get calcula internamente (função amplamente utilizada)


*/
typedef struct point
{
    int x;
    int y;
    int z;
    
    int color;
    int screen_y;
    int screen_x;
} s_point;


/*
Tad matrix:
Encapsula a estrutura de dados matriz, implementada no tad_matrix.c
*/
typedef struct matrix
{
    void *data; //dados do s_point
	int height; //linhas
	int width; //colunas
} t_matrix;

/*
Criação e destruição
*/
t_matrix *matrix_create(int height, int width);
void	matrix_destroy(t_matrix *matrix);

/*
Manipulação dos dados armazenados em s_point
matrix get calcula o indice internamente e retorna a cordenada
corresponde de s_point, 
*/
s_point	*matrix_get(t_matrix *matrix, int x, int y);
void	matrix_set(t_matrix *matrix, int x, int y, s_point value);



#endif