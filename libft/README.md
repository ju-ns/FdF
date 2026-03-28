# Libft com Testes Automatizados (TDD)

Este projeto consiste na implementação da biblioteca `libft`, que recria funções da biblioteca padrão da linguagem C. O desenvolvimento segue a abordagem **Test-Driven Development (TDD)**, garantindo a confiabilidade das funções por meio de testes automatizados em C.

---
## 📁 Estrutura do Projeto

```
.
├── Makefile
├── libft.h
├── *.c # Implementações das funções
├── libft.a # Biblioteca estática compilada
└── test/
├── test.sh # Script para rodar todos os testes
├── test_ft_bzero.c
├── test_ft_isalnum.c
├── test_ft_isalpha.c
├── test_ft_isascii.c
├── test_ft_isdigit.c
├── test_ft_isprint.c
├── test_ft_tolower.c
└── test_ft_toupper.c
```

---

## ⚙️ Como Compilar

Compile a biblioteca estática com:

```bash
make
```

## 🧪 Como Rodar os Testes

```bash
make test
```
O script test/test.sh compilará e executará todos os testes presentes na pasta test/, exibindo resultados detalhados para cada função testada.

## ✅ Funções Implementadas e Testadas

| Função      | Descrição                         | Teste Automatizado |
|-------------|----------------------------------|--------------------|
| ft_bzero    | Zera uma área de memória          | ✅                 |
| ft_isalnum  | Verifica se é alfanumérico        | ✅                 |
| ft_isalpha  | Verifica se é caractere alfabético| ✅                 |
| ft_isascii  | Verifica se é caractere ASCII     | ✅                 |
| ft_isdigit  | Verifica se é dígito              | ✅                 |
| ft_isprint  | Verifica se é caractere imprimível| ✅                 |
| ft_tolower  | Converte caractere para minúsculo | ✅                 |
| ft_toupper  | Converte caractere para maiúsculo | ✅                 |

---

## 🧰 Comandos Make Disponíveis

| Comando    | Descrição                            |
|------------|------------------------------------|
| make       | Compila a biblioteca (libft.a)     |
| make test  | Compila e executa todos os testes   |
| make clean | Remove arquivos objeto (.o)         |
| make fclean| Remove arquivos objeto e a biblioteca|
| make re    | Executa fclean e recompila tudo     |







