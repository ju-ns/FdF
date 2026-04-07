#ifndef PARSE_H
#define PARSE_H

#include "matrix.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

/*
responsáveis por implementar o parse do valor da cordenada z
e das cores
*/
int	parse_z(char *token);
int	parse_color(char *token);

/*
Responsável por orquestrar a leitura dos dados 
vindos do arquivo .fdf
*/
t_matrix	*parse_file(const char *filename);

/*
responsáveis por fazerem a contagem e definirem o tamanho
total que a matriz precisa ter
*/
int	get_map_size(const char *filename, int *width, int *height);
int	count_cols(const char *str);

/*
prepara os dados antes de passar para a fiil_points 
que preenche os dados na matriz. Se falhar libera os 
tokens e retorna 0
*/
int	parse_line(t_matrix *matrix, char *line, int y);

/*
funções utilitarias de gerenciamente de memoria
e validações para o parse
*/
int	cleanup(char *line, int fd, int exit_code);
void	free_split(char **str);
int	is_valid_int(char *str);
int	is_valid_color(char *str);
int	valid_extension(const char *str);
int	is_valid_token(char *str);





#endif