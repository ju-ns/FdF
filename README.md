*This project has been created as part of the 42 curriculum by jnogueir*

# Descrição

*"Este projeto envolve a representação de uma paisagem 3D em forma de wireframe"*

Se trata de um projeto básico (complexo em sua implementação porém com uma premissa básica) de computação gráfica, codificado em C. 

Tem como objetivo introduzir e pontecializar os fundamentos da programação gráfica, com foco em colocar pontos no espaço, conectá-los e principalmente, como modelar paisagens 3D.


# Módulos

Cada módulo foi estruturado com uma responsabilidade especifica, seguindo o principio de sepação de responsabilidades para melhorar a organização, reutilização e manutenção do código.

## Parse

Módulos responsáveis pelas validações e pela leitura do arquivo `.fdf`, convertendo
seu conteúdo em uma estrutura de dados pronta para ser renderizada.

O processo ocorre em duas passagens sobre o arquivo:

- **Primeira passagem** (`parse_size.c`): lê o arquivo para determinar as dimensões
do mapa, contando linhas e tokens por linha, validando que todas as linhas possuem
a mesma largura. Com isso, aloca a matriz com as dimensões corretas.

- **Segunda passagem** (`parse_file.c`): percorre o arquivo novamente, preenchendo
cada ponto da matriz com seus dados reais via `parse_line` → `fill_points`.

### Validações (`validations.c`)

- **Extensão:** verifica se o arquivo possui a extensão `.fdf`
- **Token:** valida cada token da linha, que pode ter o formato `z` ou `z,0xCOR`
- **Coordenada z:** aceita inteiros com ou sem sinal (`+`, `-`)
- **Cor:** valida o formato hexadecimal `0xRRGGBB` com dígitos `0-9`, `a-f` ou `A-F`

### Extração de dados (`parse_color.c`)

Cada token é separado por vírgula para extrair:
- **`parse_z`** — converte a parte numérica para `int` via `ft_atoi`
- **`parse_color`** — converte a parte hexadecimal via `ft_atoi_base(str, 16)`,
retornando `DEFAULT_COLOR` caso nenhuma cor seja especificada

### Utilitários (`parse_utils.c`)

- **`free_split`** — libera arrays alocadas pelo `ft_split`
- **`cleanup`** — fecha o `fd` e libera a linha pendente em caso de erro

## Matriz

Modulo responsável por implementar o TAD matriz, que serve como estrutura central de armazenamento dos pontos do mapa.

A matriz é representada pela struct `t_matriz`, que armazena suas dimensões e um array linear de `t_point` acessado via indexação bidimensioonal. 

### Struct

```c
t_matrix {
    int width;
    int height;
    t_point *data;
}
``` 

O array `data` é alocado de forma linear (`width * heigth`) e o acesso a um ponto `(x, y)` é feito pela seguinte fórmula:

data[y * width + x]

### Funções 

- **`matrix_create`** — aloca a struct e o array de `s_point`, inicializando
  as dimensões. Retorna `NULL` em caso de falha em qualquer alocação.

- **`matrix_destroy`** — libera o array `data` e em seguida a struct,
  com guard para ponteiro nulo.

- **`matrix_get`** — recebe coordenadas `(x, y)`, valida os bounds e retorna
  um ponteiro para o `t_point` correspondente, permitindo leitura e escrita direta.

- **`matrix_set`** — recebe coordenadas e um valor `t_point`, valida os bounds
  e sobrescreve o ponto na posição indicada.

## Projection 

Núcleo geométrico do projeto, responsável por converter as coordenadas (x, y, z) da matriz em coordenadas de tela `(screen_x, screen_y)` em pontos 2d via projeção isométrica, preparando os dados para renderização 

### Como funciona

Para que representações gráficas transmitam profundidade e revelo é necessário recorrer a perspectiva, a adotada pelo projeto é a perspectiva isométrica, que por sua vez representa o objeto de forma menos deformada pois mantém as mesmas proporções de comprimento, largura e altura do objeto representado.

Assim o vetores que estão compondo o mapa são paralelos entre si, o que cria a noção de profundidade sem que elementos apareçam menores. A profundidade é expressada pelo eixo `z`, que desloca o ponto verticalmente na tela. 

As fórmulas aplicadas a cada ponto são:

screen_x = (x - y) * tile_size + offset_x
screen_y = (x + y) * tile_size / 2 - z * z_scale / 4 + offset_y

- `(x - y)` define o crescimento **horizontal** do mapa
- `(x + y)` define o crescimento **vertical** do mapa
- `z * z_scale` aplica a elevação do terreno no eixo vertical da tela

### Parâmetros de projeção
| Parâmetro | Descrição |
|---|---|
| `tile_size` | espaçamento entre os pontos do mapa |
| `z_scale` | fator de escala para a elevação |
| `offset_x` | centraliza o mapa horizontalmente na janela |
| `offset_y` | centraliza o mapa verticalmente na janela |

## Render

Responsável por transformar os dados da matriz em pixels na tela, cobrindo desde o cálculo de endereços de memória até o algoritmo de rasterização de linhas.

O pipeline de renderização segue a ordem: 

clear_image -> project -> draw_map -> mlx_put_image_to_window

### Pipeline

- **`clear_image`** - zera todos os bytes da imagem antes de cada frame, evitando artefatos visuais de frames anteriores 

- **`project`** - converte as coordenadas `(x, y, z)` da matriz em coordenadas de tela `(screen_x, screen_y)` via projeção isométrica 

- **`draw_map`** - percorre todos os pontos da matriz e conecta cada ponto ao da direita `(x+1, y)` e ao de baixo `(x, y+1)`, formando a grade do mapa.

- **`draw_line`** - rasteriza uma linha entre dois pontos usando o **algoritmo de Bresenham** 

- **`put_pixel`** - escreve um pixel diretamente na memória da imagem

---

### put_pixel e o endereçamento de memória 

A imagem é um bloco contínuo de bytes organizado em **row-major order** 

imagem = [linha 1][linha 2] ...

Para escrever um pixel na posição `(x, y)`, o endereço é calculado como: 

dst = addr + (y * line_length) + (x * bytes_per_pixel)

`line_length` é usado no lugar de `width * bytes_per_pixel` porque a MLX não garante que as linhas sejam armazenadas sem padding - `line_length` representa o tamanho real em bytes de uma linha completa da imagem.

---

### Algoritmo de Brensenham 

Rasteriza uma reta entre dois pontos `A` e `B` usando apenas aritmética inteira, evitando operações com ponto flutuante. O algoritmo mantém um **erro incremental** iniciado em `dx - dy` que decide a cada passo se avança em `x`, em `y`, ou em ambos:

```c

err = dx - dy
e2 = 2 * err
if e2 > dy -> avança em x
if e2 < dx -> avança em y

``` 

A multiplicação por 2 transforma a comparação com float em comparação inteira, mantendo a precisçaõ sem custo computacional.

---

### Interpolação de cor (`color.c`)

Cada linha do mapa é desenhada com interpolação linear entre a cor do ponto de origem e a cor do ponto de destino. O parâmetro `t` varia de `0.0` a `1.0` e representa o progresso ao longo da linha:

```c

r = r1 + (r2 - r1) * t
g = g1 + (g2 - g1) * t
b = b1 + (b2 - b1) * t

``` 

Os componetes RGB são extraídas via **bit shifting**

R = (color >> 16) & 0xFF
G = (color >> 8) & 0xFF
B = (color >> 0) & 0xFF

E remontados com: 

color = (R<<16) | (G << 8) | B

## Hooks 

Módulo responsável por gerenciar os eventos de entrada do usuário e o ciclo de vida da aplicação, conectando os eventos da MLX às ações do programa

### Funções 

- **`key_handler`** — captura eventos de teclado e executa a ação correspondente.
  Atualmente trata a tecla `ESC` encerrando a aplicação via `close_window`.

- **`close_window`** — ponto de saída da aplicação, chama `destroy_fdf` para
  liberar todos os recursos antes de encerrar o processo com `exit(0)`.

- **`destroy_fdf`** — libera todos os recursos alocados pela aplicação,
  seguindo a ordem inversa de inicialização:

imagem -> janela -> display -> matriz -> struct principal

## Graphics 

Módulo responsável pela inicialização da janela e da imagem, abstraindo a configuração da MLX e orquestrando o ciclo de vida da aplicação via `init_fdf` 

### Inicialização - `init_fdf`

Ponto de entrada do programa, orquestra a inicialização em etapas sequenciais: 

init_screen -> parse_file -> create_image -> get_image_addr -> init_projection_params

Se qualquer etapa falhar, `destroy_fdf` é chammado para liberar os recursos já alocados antes de retornar `NULL` - garantindo que não haja leaks em inicializações parciais.

### Funções

- **`init_screen`** — aloca a struct principal com `ft_calloc` (garantindo
  que todos os campos iniciem em zero), inicializa a MLX, detecta o tamanho
  da tela e cria a janela.

- **`get_screen_size`** — detecta o tamanho real do monitor via
  `mlx_get_screen_size` e aplica um fator de `0.9` para que a janela
  não ocupe 100% da tela.

- **`create_image`** — cria o buffer de imagem off-screen com as dimensões
  da janela. A renderização acontece nesse buffer antes de ser enviada para a tela.

- **`get_image_addr`** — obtém o ponteiro direto para os bytes da imagem
  via `mlx_get_data_addr`, junto com `bits_per_pixel`, `line_length` e
  `endian` — dados necessários para o `put_pixel` calcular os endereços corretamente.

- **`new_window`** — abstração sobre `mlx_new_window`.

## Escolhas técnicas 

### Separação de estruturas - `t_point`, `t_matrix`, `t_line` e `t_fdf`

O projeto adota uma separação de responsabilidades entre suas estruturas, onde cada struct encapsula exclusivamente os dados do seu domínio.

### `t_point` - como dado atômico do mapa

Representa um único ponto do mapa e concentra tudo que um ponto precisa saber

- **Posição no mapa**
- **Cor**
- **Posição na tela**

Essa separação entre coordenadas de mapa e coordenadas de tela é intencional: o parse preenche `x`, `y`, `z` e `color`; a projeção calcula `screen_x` e `screen_y` 

### `t_matrix`- o contêiner

Encapsula o array de `t_point` junto com as suas dimensões, expondo o acesso aos dados exclusivaamente via `matrix_get` e `matrix_set`. 

O objetivo aqui foi isolar a implementação interna (array linear) para baixa manutendabilidade, caso seja a estrutura interna seja alterada apenas o tad matriz deve ser atualizado.

### `t_line` - estado do algoritmo de Bresenham 

Serve como um contêiner agrupando as váriaveis intermediárias do algoritmo de Bresenham em uma struct dedicada, essa separação torna `init_line` possível - a inicialização do algoritmo fica separada em uma função própria, deixando `draw_line` responsável apenas pelo loop de rasterização.

---

### `t_fdf` - o contexto global do projeto

Centraliza todos os recursos: conexão com MLX, parâmetros de imagem, parâmetros de projeção e o ponteiro para a matriz de dados. 

o objetivo adotado é centralização dos recursos e ciclo de vida do projeto. 

### Abstração com TAD Matriz 

A `t_matrix` é implementada como uma estrutura cujo dados internos são acessados exclusivamente através de uma interface de funções, nunca diretamente pelo restante do programa.

### A interface pública 

``` c
t_matrix *matrix_create(int width, int height);
void      matrix_destroy(t_matrix *matrix);
s_point  *matrix_get(t_matrix *matrix, int x, int y);
void      matrix_set(t_matrix *matrix, int x, int y, s_point value);
```

### Benefícios dessa decisão 

**Encapsulamento:** o restante do programa opera em termos de `(x, y)` - coordenadas naturais do mapa. A conversão para índice linear é um detalhe interno do TAD, invisível para quem consome a interface 

**Segurança:** `matrix_get` realiza as validações antes de qualquer acesso, ou seja qualquer tentativa de acesso fora dos limites retorna `NULL` em vez de causar undefined behavior - os chamadores podem checar o retorno antes de usar o ponteiro.

**Gerenciamento de memória centralizado:** `matrix_create` faz duas alocações
(`t_matrix` + array de `s_point`) e `matrix_destroy` libera ambas. O restante
do programa nunca precisa saber quantas alocações a matriz envolve — basta
chamar `matrix_destroy`.

---

### Row-major ordering 

O array de `t_point` é alocado linearmente com `width * height` elementos. O acesso a um ponto `(x, y)` é mapeado para o índice linear pela fórmula:

indice = y * width + x

Cada linha do mapa oucupa `width` posições consecutivas no array. Para chegar na linha `y`, pulamos `y * width` elementos; depois somamos `x` para a coluna.

### Por que row-major ?

O acesso mais comum durante esse projeto é percorrer o mapa linha por linha tanto no parse quanto a renderização. Com essa técnica elementos da mesma linha ficam contíguos na memória, favorecendo o processador nesse padrão sequêncial (considerando principalmente o tipo de acesso aos dados que precisamos).

**obs:** É também a mesma conveção que a linguagem C adota para arrays multidimensionais nativos(`data[y][x]`), tornando o comportamento consistente e previsível.

### Rendering Off-screen

A renderização adota a técnica de **off-screen rendering** — o frame é
montado inteiramente em um buffer de memória antes de ser enviado para a tela.

#### Como funciona

A MLX mantém dois contextos separados: a **janela** (`win`) visível para o
usuário e a **imagem** (`img`) que é um buffer invisível em memória. O pipeline
de renderização opera exclusivamente sobre o buffer:

clear_image -> project -> draw_map -> mlx_put_image_to_window

Somente na última etapa, `mlx_put_image_to_window` copia o buffer completo
para a janela em uma única operação — o usuário nunca vê o frame sendo
construído pixel a pixel.

#### Por que essa abordagem

Sem off-screen rendering, cada `put_pixel` escreveria diretamente na janela
visível. Como um frame do FdF envolve milhares de chamadas a `put_pixel`, o
usuário veria o mapa sendo desenhado linha por linha a cada frame — o
chamado **flickering**.

#### clear_image

Antes de montar cada frame, `clear_image` zera todos os bytes do buffer:

```c
ft_memset(fdf->addr, 0, fdf->line_length * fdf->height);
```

Sem esse passo, pixels de frames anteriores persistiriam no buffer —
especialmente relevante quando o mapa se move ou é rotacionado, onde
os pixels da posição antiga ficariam visíveis junto com os da nova posição.

## Instruções

### Requisitos

- GCC
- Make
- MLX (minilibx-linux) — incluída no repositório

### Instalação

```bash
git clone https://github.com/seu-usuario/fdf.git
cd fdf
make
```

### Uso

```bash
./fdf test_maps/42.fdf
```

Mapas de teste estão disponíveis na pasta `test_maps/`.

### Comandos make

| Comando | Descrição |
|---|---|
| `make` | compila o projeto |
| `make clean` | remove os arquivos objeto |
| `make fclean` | remove os arquivos objeto e o executável |
| `make re` | recompila o projeto do zero |

## Recursos 

| Recurso | Descrição | Link |
|---|---|---|
| Isometric Tiles Math — Clint Bellanger | Derivação das fórmulas de projeção isométrica | [clintbellanger.net](https://clintbellanger.net/articles/isometric_math/) |
| Isometric projection — Wikipedia | Definição formal e base geométrica da projeção isométrica | [wikipedia.org](https://en.wikipedia.org/wiki/Isometric_projection) |
| Isometric Cordinates | Cálculo das coordenadas isométricas  |[isometric-tiles.org](https://isometric-tiles.readthedocs.io/en/latest/#:~:text=screenx%20=%20x%2Dcoordinate%20of%20the,ight2)
| Perspectiva e Desenho técnico | Explicações detalhadas a respeito das diferentes perspectivas e suas caracteristicas | [exatas-ufpr](https://exatas.ufpr.br/degraf_deise/wp-content/uploads/sites/9/2014/09/apostila-desenho-tecnico-2015-Parte-2.pdf)
| Bresenham's line algorithm — Wikipedia | Algoritmo de rasterização de linhas com aritmética inteira | [wikipedia.org](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm) |
| Tipos abstratos de dados | Estruturação de interfaces e implementações de estruturas de dados | [apostila-ufg](https://ww2.inf.ufg.br/~hebert/disc/aed1/AED1_06_TAD.pdf)
| Row-Major | Descrição da técnica row-major e seus cálculos | [udrc.org](https://udrc.lkouniv.ac.in/Content/DepartmentContent/SM_33e8988e-a510-4c08-a528-c08d3bd5607e_58.pdf)
| Matrizes | Descrições a respeito de matrizes | [ufpr](https://www.inf.ufpr.br/carmem/ci180/aulas/aula21/11a-Matrizes.pdf)

### Uso de IA

Ferramentas de IA generativa foram utilizadas como recurso de pesquisa e consulta
durante o desenvolvimento — para pesquisar conceitos e revisar a
documentação. Todo o código foi escrito e compreendido pelo autor.

| Ferramenta | Uso |
|---|---|
| Claude (Anthropic) | Pesquisa, consulta técnica e auxílio na documentação |
| Chat GPT | Pesquisa e consulta técnica | 











