#ifndef MATRIX_H
#define MATRIX_H

/*
Tad matrix:
Encapsula a estrutura de dados matriz, implementada no tad_matrix.c
*/
typedef struct matrix
{
    void *data; //dados do s_point
	int height; //colunas
	int width; //linhas
} t_matrix;

/*
Criação e destruição
*/
t_matrix *matrix_create(int height, int width);
void	matrix_destroy(t_matrix *matrix);

/*
Leitura e escrita de dados
*/
void	*matrix_get(t_matrix *matrix, int x, int y);
void	matrix_set(t_matrix *matrix, int x, int y, s_point value);



#endif