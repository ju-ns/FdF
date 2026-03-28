/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:50:33 by marvin            #+#    #+#             */
/*   Updated: 2025/08/04 15:50:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void free_split(char **result, int i){
    while(i > 0){
        free(result[--i]);
    }
    free(result);
}

//conta quantas palavras há na string  pulando os separadores
static int count_words(const char *s, char c)
{
    int count; //contador auxiliar
    int word; // flag 

    count = 0;
    word = 0;
    while(*s) //percorre cada caractere da string até o fim (\0)
    {
        if(*s != c && word == 0)
        {
            word = 1; //marca que está dentro de uma palavra
            count++; //acumula a quantidade de palavras
        }
        else if (*s == c)
            word = 0; //zera a variavel quando acha um separador
        s++;//itera sobre a string 
    }
    return (count); //retorna o numero total de palavras 
}
//basicamente conta quantas palavras existem na string considerando o caractere c
//como separador

static char *extract_next_word(const char *s, char c, int *index)
{
    size_t end;
    size_t start;

    if (!s)
        return (NULL); //se a string for null retorna null
    end = *index; //começa a busca na posição atual passada como referência 
    while(s[end] == c) //pula todos os caracteres separadores consecutivos
        end++;
    start = end; //marca o inicio da palavra depois que pulamos os separadores
    while(s[end] && s[end] != c) //avança até o fim da palavra (até encontrar separador ou o fim da string)
        end++;
    *index = end; //atualiza o index para o proximo caractere após a palavra extraída 
    if(end > start)
        return (ft_substr(s, start, end - start)); //retorna uma substring da palavra extraída 
    return(NULL);
}

char **ft_split(const char *s, char c)
{
    char **result;
    int i;
    int end;
    int words;

    if(!s)
        return (NULL); //retorna null se a string for null
    words = count_words(s,c); //utiliza a função auxiliar para retornar quantas substrings (palavras)
    result = malloc(sizeof(char *) * (words + 1)); //aloca um array de ponteiros para strings
    if(!result)
        return (NULL); //se a alocação falhar retorna null
    end = 0; //indice inicial para buscar as palavras 
    i = 0;
    while(i < words){
        result[i] = extract_next_word(s,c, &end); //extrai cada palavra e armazena no array
        if(!result[i]){
            free_split(result, i);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL; //marca o fim do array com null
    return (result); //retorna o array de strings 
}
//result = malloc(sizeof(char *) * (words + 1));
//a ft_split retorna varias strings separadas da string original -> cada palavra é uma string idependente, que é um ponteiro para char
//para guardar todas essas palavras, precisamos de um array de ponteiros para char - ou seja, um vetor onde cada elemento aponta para uma palavra


//replicando a ft_split 
int count(int c, char *s)
{
    int n;
    int flag;
    n = 0;
    flag = 0;
    while(*s)
    {
        if(flag == 0 && *s != c)
        {
            flag = 1;
            n++;
        }
        else if (*s == c)
            flag = 0;
    }
    return (n);
}

