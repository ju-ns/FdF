#include "ft_printf.h"

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

int ft_putstr(char *s)
{
    int i = 0;

    if (!s)
        return ft_putstr("(null)");
    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    return i;
}