#ifndef FDF_H
# define FDF_H

#define DEFAULT_COLOR 0xFFFFFF
#include "matrix.h"

typedef struct fdf 
{
    void *data_screen;
    void *win;
    void *img; //ponteiro da imagem, retornado pelo mlx_new_image
    char *addr; //endereço do primeiro pixel na memoria
    
    int bits_per_pixel; //quantos bits representa cada pixel
    int line_length; // quantos bytes tem cada linha horizontal da imagem
    int endian; // a ordem dos bbytes da cor 

    t_matrix *matrix;
    
    int width; //colunas 
    int height; // linhas

    int offset_x; //valores somados de screen_x e screen_y de cada ponto para centralizar o mapa na janela
    int offset_y;
    int tile_size; //tamanho em pixel de cada "quadradinho" do mapa, controla quao grande o mapa aparece na tela
    int z_scale; // fator que controla o quanto de altura z afeta visualmente o mapa
} t_fdf;


#endif