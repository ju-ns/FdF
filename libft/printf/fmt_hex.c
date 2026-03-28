#include "ft_printf.h"

int ft_putnbr_base(unsigned long n, char *base)
{
    int count = 0;
    unsigned long base_len = 0;

    while(base[base_len])
        base_len++;
    if(n >= base_len)
        count += ft_putnbr_base(n / base_len, base);
    count += ft_putchar(base[n % base_len]);
    return count;
}