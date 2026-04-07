
/*
utiliza aritmetica binária para tratarmos as cores
para pegar o vermelho >> 16 move os bits 16 posições para a direita
o FF que estava na posiçãp do R agora está no final 
& 0xFF garante que só ficam os 8 bits do R zerando o resto
*/
int get_r(int color)
{
    return((color >> 16) & 0xFF);
}

int get_g(int color)
{
    return((color >> 8) & 0xFF);
}

int get_b(int color)
{
    return (color & 0xFF);
}

int create_rgb(int r, int g, int b)
{
    return((r << 16) | (g << 8) | b);
}

/*
junta tudo para formar as cores 
variavel t = valor entre 0.0 e 1.0 que representa o quanto você está entre as duas cores
*/
int interpolate_color(int color1, int color2, float t)
{
    int r;
    int g;
    int b;

    r = get_r(color1) + (get_r(color2) - get_r(color1)) * t;
    g = get_g(color1) + (get_g(color2) - get_g(color1)) * t;
    b = get_b(color1) + (get_b(color2) - get_b(color1)) * t;

    return (create_rgb(r, g, b));
}