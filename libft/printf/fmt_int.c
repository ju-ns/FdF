#include "ft_printf.h"

int ft_putnbr_unsigned(unsigned int n)
{
    int count = 0;
    if(n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    count += ft_putchar((n % 10) + '0');
    return count;
}
int ft_putnbr(int n)
{
    long num = n;
    int count = 0;

    if (num < 0)
    {
        count += ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        count += ft_putnbr(num / 10);
    count += ft_putchar((num % 10) + '0');
    return count;
}